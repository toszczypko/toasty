CC=gcc
INCLUDES=-I../src
BUILD_DIR=build

.PHONY: all clean

all: ${BUILD_DIR}/basic | ${BUILD_DIR}
	./$<

${BUILD_DIR}/basic: basic.c | ${BUILD_DIR}
	${CC} ${INCLUDES} $< -o $@

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -fr ${BUILD_DIR}
