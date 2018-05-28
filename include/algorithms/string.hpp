//
// Created by Amir Sangi on 2018-05-23.
//

#ifndef ALGORITHMS_STRING_ALGORITHMS_HPP
#define ALGORITHMS_STRING_ALGORITHMS_HPP

#include <string>
#include <vector>

namespace sangi {

    // Find the length of the longest substring(s) of a and b
    int LongestCommonSubstring(const std::string& a, const std::string& b);

    // Return indices where pattern appears in text using brute force search
    std::vector<size_t> BruteForcePatternSearch(const std::string& text, const std::string& pattern);

    // Return indices where pattern appears in text using the KMP algorithm
    std::vector<size_t> KMPSearch(const std::string& text, const std::string& pattern);

} // namespace sangi

#endif //ALGORITHMS_STRING_ALGORITHMS_HPP
