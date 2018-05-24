//
// Created by Amir Sangi on 2018-05-23.
//

#include <string>
#include <vector>
#include "algorithms/string.hpp"

using std::string;
using std::vector;

// TODO: Finish Impl
vector<string> sangi::KCommonSubstring(const string a, const string b, size_t k) {
    vector<string> substrings;
    return substrings;
}


// TODO: Finish Impl
vector<string> sangi::LongestCommonSubstring(const string a, const string b) {
    vector<string> substrings;
    return substrings;
}


vector<int> sangi::BruteForcePatternSearch(const std::string text, const std::string pattern) {
    vector<int> indices;

    size_t M = pattern.size();
    size_t N = text.size();

    for (size_t i = 0; i < N - M; ++i) {

        size_t j;
        for (j = 0; j < M; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // Pattern found
        if (j == M) { indices.emplace_back(i); }
    }

    return indices;
}


// TODO: Finish Impl
vector<int> GenerateFailureTable(const std::string pattern) {
    return vector<int>(); // stub
}

// TODO: Finish Impl
vector<int> sangi::KMPSearch(const std::string text, const std::string pattern) {
    vector<int> table = GenerateFailureTable(pattern);
    vector<int> indices;
    return indices;
}


