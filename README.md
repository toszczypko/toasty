# Toasty

Toasty is a lightweight and minimalistic unit testing framework for C. It provides a simple way to define and execute unit tests without requiring external dependencies.

## Getting Started

Toasty is a header-only framework. To use, simply include `toasty.h` in your project:
```C
#include "toasty.h"
```

## Usage

### Defining Tests

Define a test case using the `TEST(name)` macro:
```C
#include "toasty.h"

TEST(test_example) {
    TEST_ASSERT_EQUAL(4, 2 + 2);
}
```

### Running Tests

Test registration is done automatically when  the test is defined. To execute all tests in file, use the `RunTests()` function:
```C
int main() {
    return RunTests();
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
