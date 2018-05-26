//
// Created by Amir Sangi on 2018-05-23.
//

#ifndef ALGORITHMS_STRING_ALGORITHMS_HPP
#define ALGORITHMS_STRING_ALGORITHMS_HPP

#include <string>
#include <vector>

namespace sangi {

    // Find the longest substrings of a and b of length k
    std::vector<std::string> KCommonSubstring(const std::string a, const std::string b, size_t k);

    // Find the longest substrings of a and b
    std::vector<std::string> LongestCommonSubstring(const std::string a, const std::string b);

    // Return indices where pattern appears in text using brute force search
    std::vector<size_t> BruteForcePatternSearch(const std::string text, const std::string pattern);

    // Return indices where pattern appears in text using the KMP algorithm
    std::vector<size_t> KMPSearch(const std::string text, const std::string pattern);

} // namespace sangi

#endif //ALGORITHMS_STRING_ALGORITHMS_HPP
