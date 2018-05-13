//
// Created by Amir Sangi on 2018-04-30.
//

#ifndef ALGORITHMS_ALGORITHMS_H
#define ALGORITHMS_ALGORITHMS_H

#include <vector>
#include "utility.hpp"

namespace sangi {

    template <class Iterator>
    void QuickSort(Iterator begin, Iterator end) {
        size_t size = end - begin;

        // Base case
        if (size < 2) return;

        // Pivot chosen randomly
        size_t pivot_index = RandomNumber(0, size);

        // Retrieve a pivot value
        typename std::iterator_traits<Iterator>::value_type pivot_value = *(begin + pivot_index);

        // Place pivot at the beginning for iteration over all other values
        std::swap(*begin, *(begin + pivot_index));

        // Place all smaller elements on the left side of the container
        int i = 1;
        for (size_t j = 1; j < size; ++j) {
            if (*(begin + j) < pivot_value) {
                std::swap(*(begin + j), *(begin + i));
                ++i;
            }
        }

        // i - 1 is the index of the last element smaller than pivot
        auto new_pivot_pos = begin + i - 1;

        // Swap pivot with last element smaller than pivot
        std::swap(*begin, *new_pivot_pos);

        // Sort left/right of new pivot index
        QuickSort(begin, new_pivot_pos);
        QuickSort(begin + i, end);
    }

    template <class Iterator>
    void MergeSort(Iterator begin, Iterator end) {
        size_t size = end - begin;

        // Base case
        if (size < 2) return;

        // Merge left/right of container
        size_t middle = size / 2;
        Iterator right_start = begin + middle;
        MergeSort(begin, right_start);
        MergeSort(right_start, end);

        // Merge left/right of container
        size_t left_size = middle;
        size_t right_size = size - middle;

        std::vector<typename std::iterator_traits<Iterator>::value_type> temp(size);
        size_t i, j, k;
        i = j = k = 0;
        while (i < left_size && j < right_size) {
            auto i_value = *(begin + i);
            auto j_value = *(right_start + j);

            if (i_value < j_value) {
                temp[k] = i_value;
                ++i;
            }
            else {
                temp[k] = j_value;
                ++j;
            }
            ++k;
        }

        // Place remaining elements from left side
        if (i < left_size) {
            std::copy(begin + i, right_start, temp.begin() + k);
        }

        // Place remaining elements from right side
        if (j < right_size) {
            std::copy(right_start + j, end, temp.begin() + k);
        }

        // Place values back into container
        std::copy(temp.begin(), temp.end(), begin);
    }

    // Non-comparative signed integer sort
    void RadixSort(std::vector<int>& data, size_t base=10);

} // namespace sangi

#endif //ALGORITHMS_ALGORITHMS_H
