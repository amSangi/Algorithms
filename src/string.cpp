//
// Created by Amir Sangi on 2018-05-23.
//

#include <array>
#include <string>
#include <vector>
#include "algorithms/string.hpp"

using std::string;
using std::vector;


int sangi::LongestCommonSubstring(const string& a, const string& b) {
    const size_t N = a.size();
    const size_t M = b.size();

    int dp[N + 1][M + 1];
    dp[0][0] = 0;

    int longest_length = 0;

    // Find substrings
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                longest_length = std::max(longest_length, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return longest_length;
}


vector<size_t> sangi::BruteForcePatternSearch(const std::string& text, const std::string& pattern) {
    vector<size_t> indices;

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

// Store the lengths of the maximum matching proper prefix which is also a suffix
vector<size_t> GenerateShiftVector(const std::string& pattern) {
    size_t M = pattern.size();
    vector<size_t> shift_vector(M);

    size_t i = 0, j = 1;
    shift_vector[0] = 0;


    while (j < M) {
        if (pattern[i] == pattern[j]) {
            shift_vector[j] =  ++i;
            ++j;
        }
        else {
            if (i == 0) {
                shift_vector[j] = 0;
                ++j;
            }
            else {
                i = shift_vector[i - 1];
            }
        }

    }

    return shift_vector;
}


vector<size_t > sangi::KMPSearch(const std::string& text, const std::string& pattern) {
    size_t N = text.size();
    size_t M = pattern.size();
    if (N < M) { return vector<size_t >(); }

    vector<size_t> shift_vector = GenerateShiftVector(pattern);
    vector<size_t> indices;

    // i - text index, j - pattern index
    size_t i = 0, j = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            ++i;
            ++j;
        }

        if (j == M) {
            // Pattern match found
            indices.emplace_back(i - j);
            // Shift pattern forward
            j = shift_vector[j - 1];
        }
        else if (i < N && pattern[j] != text[i]) {
            if (j) {
                // Shift the pattern forward
                j = shift_vector[j - 1];
            }
            else {
                // Pattern can't match - move text index forward
                ++i;
            }
        }

    }

    return indices;
}


