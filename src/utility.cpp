//
// Created by Amir Sangi on 2018-05-08.
//

#include <algorithms/utility.hpp>
#include <cstdlib>
#include <ctime>


size_t sangi::RandomNumber(size_t begin, size_t last) {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % last + begin;
}

size_t sangi::CountDigits(int number) {
    size_t digit_count = 1;
    while (number /= 10)
        ++digit_count;

    return digit_count;
}
