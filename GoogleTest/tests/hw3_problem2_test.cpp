#include <gtest/gtest.h>
#include "../hw3_problem2.h"

TEST(ReverseOdd, AllStringsOdd) {
    const char* inputOne = "Daddy";
    const char* inputTwo = "Pig";
    const char* inputThree = "Mommy";

    const char* input[] = {inputOne, inputTwo, inputThree};

    struct ReverseResult result = reverseOdd(input, 3);
    const char* expected[] = {"yddaD", "giP", "ymmoM"};

    EXPECT_EQ(true, result.success);
    for (int a = 0; a < 3; a++) {
        EXPECT_STREQ(expected[a], result.reversedStrings[a]);
    }
}

TEST(ReverseOdd, OneStringEven) {
    const char* inputOne = "Daddy";
    const char* inputTwo = "Pig";
    const char* inputThree = "Mommy!";

    const char* input[] = {inputOne, inputTwo, inputThree};

    struct ReverseResult result = reverseOdd(input, 3);

    EXPECT_EQ(false, result.success);
}
