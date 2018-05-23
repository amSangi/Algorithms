//
// Created by Amir Sangi on 2018-05-22.
//

#include <gtest/gtest.h>
#include "algorithms/duplicate.hpp"

using namespace sangi;

TEST(TestRemoveDuplicate, SortedIntegers) {
    std::vector<int> vec{1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7, 8, 8, 8};

    size_t new_size = RemoveSortedDuplicates(vec);

    EXPECT_EQ(8, new_size);
    EXPECT_EQ(8, vec.size());
    for (size_t i = 1; i < 9; ++i) {
        EXPECT_EQ(i, vec[i - 1]);
    }
}


TEST(TestRemoveDuplicate, SortedCharacters) {
    std::vector<char> vec{'a', 'a', 'b', 'b', 'c', 'd', 'd', 'e', 'e', 'f', 'f', 'g', 'g', 'h', 'h', 'h'};

    size_t new_size = RemoveSortedDuplicates(vec);

    EXPECT_EQ(8, new_size);
    EXPECT_EQ(8, vec.size());

    char expected[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (size_t i = 0; i < 8; ++i) {
        EXPECT_EQ(expected[i], vec[i]);
    }
}


TEST(TestRemoveDuplicate, UnsortedIntegers) {
    std::vector<int> vec{6, 7, 3, 4, 1, 2, 2, 1, 1, 4, 1, 3, 3, 2, 6, 6, 6, 5, 8, 5, 8, 7, 7, 7, 8};

    size_t new_size = RemoveUnsortedDuplicates(vec);

    EXPECT_EQ(8, new_size);
    EXPECT_EQ(8, vec.size());
    for (size_t i = 1; i < 9; ++i) {
        EXPECT_EQ(i, vec[i - 1]);
    }
}


TEST(TestRemoveDuplicate, UnsortedCharacters) {
    std::vector<char> vec{'h', 'h', 'a', 'b', 'a', 'd', 'g', 'g', 'f', 'f', 'e', 'e', 'a', 'b', 'c', 'c', 'd'};

    size_t new_size = RemoveUnsortedDuplicates(vec);

    EXPECT_EQ(8, new_size);
    EXPECT_EQ(8, vec.size());

    char expected[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (size_t i = 0; i < 8; ++i) {
        EXPECT_EQ(expected[i], vec[i]);
    }
}