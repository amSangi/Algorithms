//
// Created by Amir Sangi on 2018-05-01.
//

#include <vector>
#include <cmath>
#include "sort.hpp"
#include "utility.hpp"

using std::vector;

namespace sangi {

    /********** RadixSort Definition **********/

    // Place elements in the list into bucket based on base-digit
    void ListToBuckets(size_t base,
                       size_t iteration,
                       vector<int>& list,
                       vector<vector<int>>& buckets) {
        double power = pow(base, iteration);

        for (int n : list) {

            double value = n / power;
            auto floor_value = static_cast<int>(value);

            size_t digit = floor_value % base;
            buckets[digit].push_back(n);
        }

        list.clear();
    }

    // Re-order elements in buckets back into a list
    void BucketsToList(vector<int>& list, vector<vector<int>>& buckets) {
        for (auto&& bucket : buckets) {
            for (int n : bucket) {
                list.push_back(n);
            }
            bucket.clear();
        }
    }

    void RadixSort(vector<int>& data, size_t base) {

        // Retrieve digit count of integer with most digits
        int max_value = *std::max_element(data.begin(), data.end());
        int min_value = *std::min_element(data.begin(), data.end());
        size_t max_digit_count = CountDigits(max_value);
        size_t min_digit_count = CountDigits(min_value);
        size_t digits = max_digit_count > min_digit_count ? max_digit_count : min_digit_count;

        // Construct base number of buckets
        vector<vector<int>> buckets(base, vector<int>());

        // Sort based on digits
        size_t iteration = 0;
        while (iteration < digits) {
            ListToBuckets(base, iteration, data, buckets);
            BucketsToList(data, buckets);
            ++iteration;
        }

        if (base < 2) return;

        // Sort negative values
        for (int n : data) {
            if (n < 0) {
                auto it = buckets[0].begin();
                buckets[0].insert(it, n);
            }
            else {
                buckets[1].push_back(n);
            }
        }
        data.clear();
        BucketsToList(data, buckets);
    }

} // namespace sangi;