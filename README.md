# Toasty

Toasty is a lightweight and minimalistic unit testing framework for C. It provides a simple way to define and execute unit tests without requiring external dependencies.

## Getting Started

Toasty is a stb-style header-only framework. To use it, simply include `toasty.h` in your project:
```C
#include "toasty.h"
```
Since `toasty.h` follows the stb-style pattern, you also must define `TOASTY_IMPLEMENTATION` in one source file before including the header to provide the implementation:
```C
#define TOASTY_IMPLEMENTATION
#include "toasty.h"
```

Alternatively, you can compile `toasty` as a static library which can be linked. To compile, call `make` and link created library. With this method, `TOASTY_IMPLEMENTATION` is not needed.

## Usage

### Defining Tests

Define a test case using the `TEST(name)` macro:
```C
#define TOASTY_IMPLEMENTATION
#include "toasty.h"

TEST(test_example) {
    TEST_ASSERT_EQUAL(4, 2 + 2);
}
```

### Running Tests

Test registration is done automatically when the test is defined. To execute all tests in file, use the `RunTests()` macro:
```C
int main() {
    return RunTests();
}
```

### Increase Max Tests Number

By default, only 100 tests can be defined. To increase this value, add the macro `#define TOASTY_MAX_TESTS n` before `#include "toasty.h"` in the file with implementation:
```C
#define TOASTY_IMPLEMENTATION
#define TOASTY_MAX_TESTS 200
#include "toasty.h"
```

### SetUp and TearDown

It is possible to optionally define `SetUp()` and `TearDown()` functions which will be automatically registered and called before and after each test:
```C
#define TOASTY_IMPLEMENTATION
#include "toasty.h"
#include <stdio.h>

void SetUp() {
    printf("Before test\n");
}

void TearDown() {
    printf("After test\n");
}

TEST(test_example) {
    TEST_ASSERT_TRUE(1);
}

int main() {
    return RunAll();
}
```

### Handling segfaults

By default, Toasty catches segfaults in tests and reports them as fails. To disable this behavior (e.g. for debugging), simply add the macro `#define TOASTY_IGNORE_SEGFAULTS` before `#include "toasty.h"` in the file with implementation:
```C
#define TOASTY_IMPLEMENTATION
#define TOASTY_IGNORE_SEGFAULTS
#include "toasty.h"
```

## Assertions

```
TEST_ASSERT_TRUE(condition)
```
Evaluates code in condition and fails if it evaluates to false.

```
TEST_ASSERT_FALSE(condition)
```
Evaluates code in condition and fails if it evaluates to true.

```
TEST_ASSERT_EQUAL(expected, actual)
```
Compares two integers and fails if they are not equal.

```
TEST_ASSERT_NULL(pointer)
```
Fails if pointer is not NULL.

```
TEST_ASSERT_NOT_NULL(pointer)
```
Fails if pointer is NULL.

```
TEST_ASSERT_EQUAL_INT(expected, actual);
TEST_ASSERT_EQUAL_INT8(expected, actual);
TEST_ASSERT_EQUAL_INT16(expected, actual);
TEST_ASSERT_EQUAL_INT32(expected, actual);
TEST_ASSERT_EQUAL_INT64(expected, actual);
```
Compares two integers and fails if they are not equal. Each of these assertions casts `expected` and `actual` expressions to the specified type of exact size.

```
TEST_ASSERT_EQUAL_UINT(expected, actual);
TEST_ASSERT_EQUAL_UINT8(expected, actual);
TEST_ASSERT_EQUAL_UINT16(expected, actual);
TEST_ASSERT_EQUAL_UINT32(expected, actual);
TEST_ASSERT_EQUAL_UINT64(expected, actual);
```
Same as `_INT*` tests, but cast values to unsigned integers and compares them.

```
TEST_ASSERT_EQUAL_HEX(expected, actual);
TEST_ASSERT_EQUAL_HEX8(expected, actual);
TEST_ASSERT_EQUAL_HEX16(expected, actual);
TEST_ASSERT_EQUAL_HEX32(expected, actual);
TEST_ASSERT_EQUAL_HEX64(expected, actual);
```
Same as `_UINT*` tests, but print failures as hexadecimal numbers.

