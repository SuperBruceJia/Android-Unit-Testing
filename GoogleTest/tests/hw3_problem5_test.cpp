#include <gtest/gtest.h>
#include "../hw3_problem5.h"

TEST(ChangeAmounts, EmptyListChangeAmount) {
    CoinArrays result = possibleChangeAmounts(0);

    EXPECT_EQ(0, result.size);
    EXPECT_EQ(NULL, result.arrays);
}

TEST(ChangeAmounts, SingleCoin) {
    CoinArrays result = possibleChangeAmounts(1);

    EXPECT_EQ(1, result.size);

    EXPECT_EQ(1, result.arrays[0].size);
    EXPECT_EQ(PENNY, result.arrays[0].coins[0]);
}

TEST(ChangeAmounts, SingleSolution) {
    CoinArrays result = possibleChangeAmounts(4);

    EXPECT_EQ(1, result.size);

    EXPECT_EQ(4, result.arrays[0].size);
    EXPECT_EQ(PENNY, result.arrays[0].coins[0]);
    EXPECT_EQ(PENNY, result.arrays[0].coins[1]);
    EXPECT_EQ(PENNY, result.arrays[0].coins[2]);
    EXPECT_EQ(PENNY, result.arrays[0].coins[3]);
}

TEST(ChangeAmounts, MulipleSolutions) {
    CoinArrays result = possibleChangeAmounts(11);

    EXPECT_EQ(4, result.size);

    EXPECT_EQ(2, result.arrays[0].size);
    EXPECT_EQ(PENNY, result.arrays[0].coins[0]);
    EXPECT_EQ(DIME, result.arrays[0].coins[1]);

    EXPECT_EQ(3, result.arrays[1].size);
    EXPECT_EQ(PENNY, result.arrays[1].coins[0]);
    EXPECT_EQ(NICKEL, result.arrays[1].coins[1]);
    EXPECT_EQ(NICKEL, result.arrays[1].coins[2]);

    EXPECT_EQ(7, result.arrays[2].size);
    EXPECT_EQ(PENNY, result.arrays[2].coins[0]);
    EXPECT_EQ(PENNY, result.arrays[2].coins[1]);
    EXPECT_EQ(PENNY, result.arrays[2].coins[5]);
    EXPECT_EQ(NICKEL, result.arrays[2].coins[6]);

    EXPECT_EQ(11, result.arrays[3].size);
    EXPECT_EQ(PENNY, result.arrays[3].coins[0]);
    EXPECT_EQ(PENNY, result.arrays[3].coins[1]);
    EXPECT_EQ(PENNY, result.arrays[3].coins[9]);
    EXPECT_EQ(PENNY, result.arrays[3].coins[10]);
}
