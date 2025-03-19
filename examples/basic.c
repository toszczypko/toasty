#define TOASTY_IMPLEMENTATION
#include "toasty.h"

TEST(test_assertTrueShouldSucceed) {
    TEST_ASSERT_TRUE(10 > 5);
}

TEST(test_assertEqualShouldSucceed) {
    TEST_ASSERT_EQUAL(4, 2 + 2);
}

TEST(test_assertTrueShouldFail) {
    TEST_ASSERT_TRUE(0);
}

TEST(test_assertEqualShouldFail) {
    TEST_ASSERT_EQUAL(4, 2 + 1);
}

int main() {
    return RunTests();
}
