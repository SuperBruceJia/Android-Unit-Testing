#include <gtest/gtest.h>
#include "../hw3_problem1.h"

TEST(ConcatenateTest, SingleWordInputs) {
    const char* inputOne = "Peppa";
    const char* inputTwo = "Pig";

    char* result = concatenate(inputOne, inputTwo);
    EXPECT_STREQ("PeppaPig", result);
}
