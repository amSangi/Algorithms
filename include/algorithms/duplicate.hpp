//
// Created by Amir Sangi on 2018-05-23.
//

#ifndef ALGORITHMS_DUPLICATE_HPP
#define ALGORITHMS_DUPLICATE_HPP

#include <cstddef>
#include <vector>
#include <set>

namespace sangi {

    // Remove duplicates from sorted container and return the new container size
    template<class T>
    size_t RemoveSortedDuplicates(std::vector<T>& vec) {

        size_t last_unique = 0;

        for (size_t i = 1; i < vec.size(); ++i) {
            if (vec[last_unique] != vec[i]) {
                vec[++last_unique] = vec[i];
            }
        }

        size_t new_size = last_unique + 1;
        vec.resize(new_size);
        return new_size;
    }

    // Remove duplicates from unsorted container and return the new container size
    // Function also sorts the container
    template<class T>
    size_t RemoveUnsortedDuplicates(std::vector<T>& vec) {
        std::set<T> unique_set;

        for (size_t i = 1; i < vec.size(); ++i) {
            if (unique_set.find(vec[i]) == unique_set.end()){
                unique_set.insert(vec[i]);
            }
        }

        size_t i = 0;
        for (T value : unique_set) {
            vec[i] = value;
            ++i;
        }

        vec.resize(i);
        return i;
    }

} // namespace sangi

#endif //ALGORITHMS_DUPLICATE_HPP
