// TDD testing for hash function class

#include <gtest/gtest.h>
#include <vector>
#include "../src/HashFunction.h"

using namespace std;

TEST(HashFunctionTest, sameHashValues) {
    HashFunction* h1 = new HashFunction(16, 2, 1);
    HashFunction* h2 = new HashFunction(16, 2, 1);
    vector<int>hashes1 = h1->getHashes("www.a.com");
    vector<int>hashes2 = h2->getHashes("www.a.com");
    EXPECT_TRUE(hashes1[0] == hashes2[0] && hashes1[1] == hashes2[1]);

    delete h2;
    delete h1;
}
TEST(HashFunctionTest, differentHashValues) {
    HashFunction* h1 = new HashFunction(256, 2, 1);
    HashFunction* h2 = new HashFunction(256, 1, 2);
    vector<int>hashes1 = h1->getHashes("www.google.com");
    vector<int>hashes2 = h2->getHashes("www.facebook.com");
    EXPECT_FALSE(hashes1[0] == hashes2[0] && hashes1[1] == hashes2[1]);

    delete h2;
    delete h1;
}