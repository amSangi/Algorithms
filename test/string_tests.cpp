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

    std::vector<std::string> longest_substrings = LongestCommonSubstring(a, b);
    ASSERT_EQ(1, longest_substrings.size());
    EXPECT_EQ("Geeks", longest_substrings[0]);
}


TEST(CommonSubstringTest, LongestMultipleMatch) {
    std::string a = "ABBBBACA ACCA CDA ABCBCACAFFE F";
    std::string b = "ACDABBBBACAD ACCA DDA ABCBCACAD FFE";

    std::vector<std::string> longest_substrings = LongestCommonSubstring(a, b);
    ASSERT_EQ(2, longest_substrings.size());
    EXPECT_EQ("ABBBBACA", longest_substrings[0]);
    EXPECT_EQ("ABCBCACA", longest_substrings[1]);
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