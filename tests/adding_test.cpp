// TDD for the adding part for the Bytes Array and for the URL vector

// Test the add function.
TEST(BloomPartTest, Adding) {
    BloomPart bp = new BloomPart(8, 1);
    string s = "www.example1.com";
    bp.add(s);
    EXPECT_EQ(bp.isBlack(s), true);
}

// Test the isBlack function.
TEST(BloomPartTest, isBlack) {
    BloomPart bp = new BloomPart(8, 1);
    string s = "www.example1.com";
    bp.add(s);
    EXPECT_EQ(bp.isBlack(s), true);
    EXPECT_EQ(bp.isInURL(s), true);
    EXPECT_EQ(bp.isBlack("www.example2.com"), false);
    EXPECT_EQ(bp.isBlack("www.example3.com"), false);
}

// Test the isInURL function.
TEST(BloomPartTest, isInURL) {
    BloomPart bp = new BloomPart(8, 1);
    string s = "www.example1.com";
    bp.add(s);
    EXPECT_EQ(bp.isInURL(s), true);
    EXPECT_EQ(bp.isInURL("www.example2.com"), false);
    EXPECT_EQ(bp.isInURL("www.example3.com"), false);
}
