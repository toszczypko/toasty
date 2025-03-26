CC=gcc
CFLAGS=-O2
INCLUDES=-Isrc
BUILD_DIR=build

.PHONY: test clean

${BUILD_DIR}/libtoasty.a: ${BUILD_DIR}/toasty.o | ${BUILD_DIR}
	ar rcs $@ $<

${BUILD_DIR}/toasty.o: src/toasty.h | ${BUILD_DIR}
	rm -f ${BUILD_DIR}/toasty.c
	touch ${BUILD_DIR}/toasty.c
	echo "#define TOASTY_IMPLEMENTATION" >> ${BUILD_DIR}/toasty.c
	echo "#include \"toasty.h\"" >> ${BUILD_DIR}/toasty.c
	${CC} ${CFLAGS} ${INCLUDES} -c ${BUILD_DIR}/toasty.c -o $@
	rm -f ${BUILD_DIR}/toasty.c

test: ${BUILD_DIR}/test ${BUILD_DIR}/test_setup_teardown ${BUILD_DIR}/test_int | ${BUILD_DIR}
	-./${BUILD_DIR}/test
	-./${BUILD_DIR}/test_setup_teardown
	-./${BUILD_DIR}/test_int

${BUILD_DIR}/test: tests/test.c src/toasty.h | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}/test_setup_teardown: tests/test_setup_teardown.c src/toasty.h | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}/test_int: tests/test_int.c src/toasty.h | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -fr ${BUILD_DIR}
