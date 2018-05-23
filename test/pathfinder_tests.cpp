//
// Created by Amir Sangi on 2018-05-21.
//

#include <list>
#include <gtest/gtest.h>
#include "pathfinder_test.hpp"
#include "data/undirected_graph.hpp"
#include "data/edge.hpp"
#include "algorithms/pathfinder.hpp"

using namespace sangi;

template<class T>
void ValdiatePath(std::list<T> expected, std::list<T> actual) {

    ASSERT_EQ(expected.size(), actual.size());

    typename std::list<T>::iterator it_expected = expected.begin();
    typename std::list<T>::const_iterator it_expected_end = expected.cend();
    typename std::list<T>::iterator it_actual = actual.begin();

    while (it_expected != it_expected_end) {
        EXPECT_EQ(*it_expected, *it_actual);
        ++it_expected;
        ++it_actual;
    }
}

TEST_F(PathFinderTest, SimpleBFS) {
    std::list<int> actual_int_path = pathfinder_int.BreadthFirstSearch(simple_int_graph, 0, 7);
    std::list<char> actual_char_path = pathfinder_char.BreadthFirstSearch(simple_char_graph, 'a', 'h');

    std::list<int> expected_int_path{0, 1, 2, 3, 5, 6, 7};
    std::list<char> expected_char_path{'a', 'b', 'c', 'd', 'f', 'g', 'h'};

    ValdiatePath(expected_int_path, actual_int_path);
    ValdiatePath(expected_char_path, actual_char_path);
}


TEST_F(PathFinderTest, ComplexBFS) {
    std::list<int> actual_int_path = pathfinder_int.BreadthFirstSearch(complex_int_graph, 3, 8);
    std::list<char> actual_char_path = pathfinder_char.BreadthFirstSearch(complex_char_graph, 'd', 'i');

    std::list<int> expected_int_path{3, 7, 8};
    std::list<char> expected_char_path{'d', 'h', 'i'};

    ValdiatePath(expected_int_path, actual_int_path);
    ValdiatePath(expected_char_path, actual_char_path);
}

TEST_F(PathFinderTest, SimpleDFS) {
    std::list<int> actual_int_path = pathfinder_int.DepthFirstSearch(simple_int_graph, 0, 7);
    std::list<char> actual_char_path = pathfinder_char.DepthFirstSearch(simple_char_graph, 'a', 'h');

    std::list<int> expected_int_path{0, 1, 4, 3, 5, 6, 7};
    std::list<char> expected_char_path{'a', 'b', 'e', 'd', 'f', 'g', 'h'};

    ValdiatePath(expected_int_path, actual_int_path);
    ValdiatePath(expected_char_path, actual_char_path);
}


TEST_F(PathFinderTest, ComplexDFS) {
    std::list<int> actual_int_path = pathfinder_int.DepthFirstSearch(complex_int_graph, 3, 8);
    std::list<char> actual_char_path = pathfinder_char.DepthFirstSearch(complex_char_graph, 'd', 'i');

    std::list<int> expected_int_path{3, 7, 8};
    std::list<char> expected_char_path{'d', 'h', 'i'};

    ValdiatePath(expected_int_path, actual_int_path);
    ValdiatePath(expected_char_path, actual_char_path);
}
