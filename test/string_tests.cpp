//
// Created by Amir Sangi on 2018-05-23.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "algorithms/string.hpp"

using namespace sangi;

TEST(CommonSubstringTest, LongestSingleMatch) {
    std::string a = "GeeksforGeeks";
    std::string b = "GeeksQuiz";

    int length = LongestCommonSubstring(a, b);
    EXPECT_EQ(5, length);
}


TEST(CommonSubstringTest, LongestMultipleMatch) {
    // Longest Common Substrings: ABBBBACA, ABCBCACA
    std::string a = "ABBBBACA ACCA CXDAABCBCACAFFE F";
    std::string b = "F FEABBBBACAZFFE CDA ABCBCACAV VL";

    int length = LongestCommonSubstring(a, b);
    ASSERT_EQ(8, length);
}


TEST(PatternSearchTest, BruteForceSearch) {
    std::string text = "AAAB ACACD ACDFACACD FF";
    std::string pat = "ACACD";

    std::vector<size_t> indices = BruteForcePatternSearch(text, pat);

    ASSERT_EQ(2, indices.size());
    EXPECT_EQ(5, indices[0]);
    EXPECT_EQ(15, indices[1]);
}


TEST(PatternSearchTest, KMPSearch) {
    std::string text = "AAAB ACACD ACDFACACD FF";
    std::string pat = "ACACD";

    std::vector<size_t> indices = KMPSearch(text, pat);

    ASSERT_EQ(2, indices.size());
    EXPECT_EQ(5, indices[0]);
    EXPECT_EQ(15, indices[1]);
}