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

By default, only 100 tests can be defined. To increase this value, add the macro `#define MAX_TESTS n` before `#include "toasty.h"` in the file with implementation:
```C
#define TOASTY_IMPLEMENTATION
#define MAX_TESTS 200
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

## Catch segfaults

Toasty catches segfaults in tests and reports which test has the problem. Tests with segfaults are treated as failed.