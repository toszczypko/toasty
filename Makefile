CC=gcc
CFLAGS=-O2
INCLUDES=-Isrc
BUILD_DIR=build
LIB_FILE=${BUILD_DIR}/libtoasty.a
LIBS=-Lbuild -ltoasty

.PHONY: test clean

${LIB_FILE}: ${BUILD_DIR}/toasty.o | ${BUILD_DIR}
	ar rcs $@ $<

${BUILD_DIR}/toasty.o: src/toasty.h | ${BUILD_DIR}
	${CC} ${CFLAGS} -x c ${INCLUDES} -DTOASTY_IMPLEMENTATION -c src/toasty.h -o $@

test: ${BUILD_DIR}/test ${BUILD_DIR}/test_setup_teardown ${BUILD_DIR}/test_int ${BUILD_DIR}/test_float | ${BUILD_DIR}
	./${BUILD_DIR}/test
	./${BUILD_DIR}/test_setup_teardown
	./${BUILD_DIR}/test_int
	./${BUILD_DIR}/test_float

${BUILD_DIR}/test: tests/test.c src/toasty.h ${LIB_FILE} | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@ ${LIBS}

${BUILD_DIR}/test_setup_teardown: tests/test_setup_teardown.c src/toasty.h ${LIB_FILE} | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@ ${LIBS}

${BUILD_DIR}/test_int: tests/test_int.c src/toasty.h ${LIB_FILE} | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@ ${LIBS}

${BUILD_DIR}/test_float: tests/test_float.c src/toasty.h ${LIB_FILE} | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@ ${LIBS}

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -fr ${BUILD_DIR}
