#define TOASTY_IMPLEMENTATION
#include "toasty.h"
#include <stdlib.h>

static int* ptr = NULL;
static int afterFirstTest = 0;
static int afterFirstTestValue = 0;

void SetUp() {
    ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
}

void TearDown() {
    free(ptr);
    ptr = NULL;

    if (!afterFirstTest) {
        afterFirstTest = 1;
        afterFirstTestValue = 1024;
    }
}

TEST(test_setUp) {
    TEST_ASSERT_NOT_NULL(ptr);
    TEST_ASSERT_EQUAL(10, *ptr);

    TEST_ASSERT_FALSE(afterFirstTest);
    TEST_ASSERT_EQUAL(0, afterFirstTestValue);
}

TEST(test_tearDown) {
    TEST_ASSERT_TRUE(afterFirstTest);
    TEST_ASSERT_EQUAL(1024, afterFirstTestValue);
}

int main() {
    return RunTests();
}
