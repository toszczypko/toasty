#ifndef TOASTY_H
#define TOASTY_H

#include <stdio.h>

typedef void (*TestFunc)();

typedef struct {
    const char* name;
    TestFunc func;
} TestCase;

#ifndef MAX_TESTS
#define MAX_TESTS 100
#endif // MAX_TESTS

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif // EXIT_FAILURE

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif // EXIT_SUCCESS

static TestCase tests[MAX_TESTS];
static size_t testCount = 0;
static size_t testsPassed = 0;
static size_t testsFailed = 0;
static const char* currentTestName = NULL;

#define TEST(name) \
    void name(); \
    __attribute__((constructor)) void register_##name() { \
        tests[testCount++] = (TestCase){#name, name}; \
    } \
    void name()

#define FAIL(msg, file, line) do { \
    printf("\033[1;91m[FAIL]\033[m %s %s:%d: %s\n", currentTestName, file, line, msg); \
    ++testsFailed; \
    return; \
} while(0)

#define TEST_ASSERT_TRUE(condition) if (!(condition)) { \
    FAIL("Condition is false", __FILE__, __LINE__); \
    return; \
}

#define TEST_ASSERT_FALSE(condition) if ((condition)) { \
    FAIL("Condition is true", __FILE__, __LINE__); \
    return; \
}

#define TEST_ASSERT_EQUAL(expected, actual) if ((expected) != (actual)) { \
    char msg[128]; \
    snprintf(msg, sizeof(msg), "Expected %d, but got %d", (int)(expected), (int)(actual)); \
    FAIL(msg, __FILE__, __LINE__); \
    return; \
}

#define TEST_ASSERT_NULL(pointer) if ((pointer)) { \
    FAIL("Pointer is not null", __FILE__, __LINE__); \
    return; \
}

#define TEST_ASSERT_NOT_NULL(pointer) if (!(pointer)) { \
    FAIL("Pointer is null", __FILE__, __LINE__); \
    return; \
}

static int RunTests() {
    printf("\033[1;96mRunning %zu tests...\033[m\n", testCount);
    for (size_t i = 0; i < testCount; ++i) {
        currentTestName = tests[i].name;
        size_t beforeFailCount = testsFailed;
        tests[i].func();
        if (beforeFailCount == testsFailed) {
            printf("\033[1;92m[PASS]\033[m %s\n", currentTestName);
            ++testsPassed;
        }
    }

    printf("\n\033[1;96m========== TEST SUMMARY ==========\033[m\n");
    printf(
        "\033[1mTotal:\033[m %zu | \033[1mPassed:\033[m %zu | \033[1mFailed:\033[m %zu\n",
        testCount, testsPassed, testsFailed
    );
    if (testsFailed > 0) {
        printf("\033[1;91mSome tests failed!\033[m\n");
        return EXIT_FAILURE;
    } else {
        printf("\033[1;92mAll tests passed!\033[m\n");
        return EXIT_SUCCESS;
    }
}

#endif // TOASTY_H
