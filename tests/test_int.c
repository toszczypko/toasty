#define TOASTY_IMPLEMENTATION
#include "toasty.h"

TEST(test_EqualInts) {
    TEST_ASSERT_EQUAL_INT(9998, 5000 + 4998);
}

TEST(test_EqualInt8s) {
    TEST_ASSERT_EQUAL_INT8(16, 8 + 8);
}

TEST(test_EqualInt16s) {
    TEST_ASSERT_EQUAL_INT16(32700, 32767 - 67);
}

TEST(test_EqualInt32s) {
    TEST_ASSERT_EQUAL_INT32(2147483600, 2147483647 - 47);
}

TEST(test_EqualInt64s) {
    TEST_ASSERT_EQUAL_INT64(9223372036854775800, 9223372036854775807 - 7);
}

int main() {
    return RunTests();
}
