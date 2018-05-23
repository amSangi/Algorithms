//
// Created by Amir Sangi on 2018-05-03.
//

#ifndef ALGORITHMS_UTILITY_H
#define ALGORITHMS_UTILITY_H

#include <cstddef>

namespace sangi {

    // Return a random whole number between begin and last
    size_t RandomNumber(size_t begin, size_t last);

    // Return the number of digits in an integer
    size_t CountDigits(int number);

    // Remove duplicates from container and return the new container size
    template<class Iterator>
    size_t RemoveSortedDuplicates(Iterator first, Iterator last) {
        return 0; // stub
    }

    // Remove duplicates from container and return the new container size
    template<class Iterator>
    size_t RemoveUnsortedDuplicates(Iterator first, Iterator last) {
         return 0; // stub
    }

} // namespace sangi

#endif //ALGORITHMS_UTILITY_H
