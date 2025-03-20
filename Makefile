CC=gcc
INCLUDES=-Isrc
BUILD_DIR=build

.PHONY: all clean

all: ${BUILD_DIR}/test ${BUILD_DIR}/test_setup_teardown | ${BUILD_DIR}
	-./${BUILD_DIR}/test
	-./${BUILD_DIR}/test_setup_teardown

${BUILD_DIR}/test: tests/test.c src/toasty.h | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}/test_setup_teardown: tests/test_setup_teardown.c src/toasty.h | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -fr ${BUILD_DIR}
