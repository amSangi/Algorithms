//
// Created by Amir Sangi on 2018-05-01.
//


#include <gtest/gtest.h>
#include <vector>
#include "sort.hpp"

using namespace sangi;


TEST(TestQuickSort, TestSimpleIntSort) {
    std::vector<int> vec{2, 1, 4, 0, 3};

    QuickSort(vec.begin(), vec.end());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, vec[i]);
    }
}


TEST(TestQuickSort, TestSimpleCharSort) {
    std::vector<char> vec{'a', 'f', 'b', 'z', 'd'};

    QuickSort(vec.begin(), vec.end());
    EXPECT_EQ('a', vec[0]);
    EXPECT_EQ('b', vec[1]);
    EXPECT_EQ('d', vec[2]);
    EXPECT_EQ('f', vec[3]);
    EXPECT_EQ('z', vec[4]);
}

TEST(TestMergeSort, TestSimpleIntSort) {
    std::vector<int> vec{2, 1, 4, 0, 3};

    MergeSort(vec.begin(), vec.end());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, vec[i]);
    }
}


TEST(TestMergeSort, TestSimpleCharSort) {
    std::vector<char> vec{'a', 'f', 'b', 'z', 'd'};

    MergeSort(vec.begin(), vec.end());
    EXPECT_EQ('a', vec[0]);
    EXPECT_EQ('b', vec[1]);
    EXPECT_EQ('d', vec[2]);
    EXPECT_EQ('f', vec[3]);
    EXPECT_EQ('z', vec[4]);
}


TEST(TestRadixSort, TestSimplePositiveInts) {
    std::vector<int> vec{2, 1, 4, 0, 3};

    RadixSort(vec);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, vec[i]);
    }
}


TEST(TestRadixSort, TestComplexPositiveInts) {
    std::vector<int> vec{2, 10034, 245, 9841, 46810349};

    RadixSort(vec);
    EXPECT_EQ(2, vec[0]);
    EXPECT_EQ(245, vec[1]);
    EXPECT_EQ(9841, vec[2]);
    EXPECT_EQ(10034, vec[3]);
    EXPECT_EQ(46810349, vec[4]);
}


TEST(TestRadixSort, TestComplexNegativeInts) {
    std::vector<int> vec{-2, -10034, -245, -9841, -46810349, -46810349};

    RadixSort(vec);
    EXPECT_EQ(-46810349, vec[0]);
    EXPECT_EQ(-46810349, vec[1]);
    EXPECT_EQ(-10034, vec[2]);
    EXPECT_EQ(-9841, vec[3]);
    EXPECT_EQ(-245, vec[4]);
    EXPECT_EQ(-2, vec[5]);
}


TEST(TestRadixSort, TestComplexMixedInts) {
    std::vector<int> vec{2, -10034, -245, 9841, 46810349, -46810349};

    RadixSort(vec);
    EXPECT_EQ(-46810349, vec[0]);
    EXPECT_EQ(-10034, vec[1]);
    EXPECT_EQ(-245, vec[2]);
    EXPECT_EQ(2, vec[3]);
    EXPECT_EQ(9841, vec[4]);
    EXPECT_EQ(46810349, vec[5]);
}


