#define TOASTY_IMPLEMENTATION
#include "toasty.h"

TEST(test_isTrue) {
    TEST_ASSERT_TRUE(10 > 5);
}

TEST(test_isFalse) {
    TEST_ASSERT_FALSE(10 == 5);
}

TEST(test_isEqual) {
    TEST_ASSERT_EQUAL(4, 2 + 2);
}

TEST(test_isNull) {
    const char* ptr = NULL;
    TEST_ASSERT_NULL(ptr);
}

TEST(test_isNotNull) {
    const char* ptr = "Hello world!";
    TEST_ASSERT_NOT_NULL(ptr);
}

int main() {
    return RunTests();
}
