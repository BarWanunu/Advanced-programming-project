// TDD testing for bloom part (second part of the project)

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "../src/bloomPart.cpp"
using namespace std;

// Test the constructor.


TEST(BloomPartTest, Constructor) {
    bloomPart bp(128, 2);
    EXPECT_EQ(128, bp.size());
    EXPECT_EQ(1, bp.numFunctions());
    EXPECT_EQ(2, bp.numHashes());
    bloomPart bp2(256, 2, 1);
    EXPECT_EQ(256, bp2.size());
    EXPECT_EQ(2, bp2.numFunctions());
    EXPECT_EQ(3, bp2.numHashes());
}

// Test the input validity.
TEST(BloomPartTest, inputValidity) {
    EXPECT_FALSE(bloomPart::inputValidity(a));
    EXPECT_FALSE(bloomPart::inputValidity(128));
    EXPECT_FALSE(bloomPart::inputValidity(128 a));
    EXPECT_TRUE(bloomPart::inputValidity(128 1));
    EXPECT_TRUE(bloomPart::inputValidity(128 2 2));
    EXPECT_FALSE(bloomPart::inputValidity(128 2 2 1));
}
