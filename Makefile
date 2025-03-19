CC=gcc
INCLUDES=-Isrc
BUILD_DIR=build
TARGET=test-toasty

.PHONY: all clean

all: ${BUILD_DIR}/${TARGET} | ${BUILD_DIR}
	./$<

${BUILD_DIR}/${TARGET}: tests/test.c | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -fr ${BUILD_DIR}
