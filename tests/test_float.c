#include "toasty.h"

TEST(test_EqualFloat) {
    TEST_ASSERT_EQUAL_FLOAT(0.3f, 0.1f + 0.2f);
}

TEST(test_EqualDouble) {
    TEST_ASSERT_EQUAL_DOUBLE(0.3, 0.1 + 0.2);
}

int main() {
    return RunTests();
}
