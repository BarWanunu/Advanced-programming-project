// TDD testing for bloom part

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "BloomPart.cpp"
#include "CheckURL.cpp"
#include "AddURL.cpp"

using namespace std;

// Test the constructor.

TEST(BloomPartTest, Constructor) {
    map<string, ICommand*> commands;
    ICommand* addU = new AddURL();
    commands["1"]= addU;
    ICommand* checkU = new CheckURL();
    commands["2"]=checkU;
    int* arr = new int[3];
    arr[0] = 128;
    arr[1] = 2;
    arr[2] = 0;
    BloomPart* bp = new BloomPart(commands, arr);
    EXPECT_EQ(128, bp->size());
    EXPECT_EQ(1, bp->numfunctions());
    EXPECT_EQ(2, bp->numhashes());
    arr[0] = 256;
    arr[1] = 2;
    arr[2] = 1;
    BloomPart* bp2 = new BloomPart(commands,arr);
    EXPECT_EQ(256, bp2->size());
    EXPECT_EQ(2, bp2->numfunctions());
    EXPECT_EQ(3, bp2->numhashes());
    delete bp2;
    delete bp;
    delete[] arr;
}
