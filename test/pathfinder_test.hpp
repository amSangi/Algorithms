//
// Created by Amir Sangi on 2018-05-22.
//

#ifndef ALGORITHMS_PATHFINDER_TEST_HPP
#define ALGORITHMS_PATHFINDER_TEST_HPP

#include <gtest/gtest.h>
#include "data/undirected_graph.hpp"
#include "algorithms/pathfinder.hpp"

using namespace sangi;

class PathFinderTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        SetUpIntGraphs();
        SetUpCharGraphs();
    }

    void SetUpIntGraphs() {

        // Simple Int UndirectedGraph
        Edge<int> sc1(0, 1, 25);
        Edge<int> sc2(1, 2, 3.3);
        Edge<int> sc3(2, 3, 4.4);
        Edge<int> sc4(3, 4, 5.5);
        Edge<int> sc5(3, 5, 2.3);
        Edge<int> sc6(4, 1, 33);
        Edge<int> sc7(5, 6, 2);
        Edge<int> sc8(6, 7, 2);
        Edge<int> sc9(7, 6, 1);

        std::vector<Edge<int>> sc_edges{sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9};
        simple_int_graph.AddEdges(sc_edges);

        // Complex Int UndirectedGraph
        Edge<int> cc1(3, 5, 3);
        Edge<int> cc2(3, 1, 11);
        Edge<int> cc3(5, 4, 6.3);
        Edge<int> cc4(5, 2, 1.5);
        Edge<int> cc5(1, 7, 8);
        Edge<int> cc6(7, 2, 13);
        Edge<int> cc7(4, 6, 3);
        Edge<int> cc8(2, 6, 23);
        Edge<int> cc9(6, 8, 8.7);
        Edge<int> cc10(7, 3, 3); // go back to 3
        Edge<int> cc11(7, 8, 34);

        std::vector<Edge<int>> cc_edges{cc1, cc2, cc3, cc4, cc5, cc6, cc7, cc8, cc9, cc10, cc11};
        complex_int_graph.AddEdges(cc_edges);
    }

    void SetUpCharGraphs() {
        // Simple char graph
        Edge<char> sc1('a', 'b', 25);
        Edge<char> sc2('b', 'c', 3.3);
        Edge<char> sc3('c', 'd', 4.4);
        Edge<char> sc4('d', 'e', 5.5);
        Edge<char> sc5('d', 'f', 2.3);
        Edge<char> sc6('e', 'b', 33);
        Edge<char> sc7('f', 'g', 2);
        Edge<char> sc8('g', 'h', 2);
        Edge<char> sc9('h', 'g', 1);

        std::vector<Edge<char>> sc_edges{sc1, sc2, sc3, sc4, sc5, sc6, sc7, sc8, sc9};
        simple_char_graph.AddEdges(sc_edges);


        // Complex char graph
        // https://qph.fs.quoracdn.net/main-qimg-e1b92fc2dbad33ba49fdd5bcbaad7568
        Edge<char> cc1('d', 'f', 3);
        Edge<char> cc2('d', 'b', 11);
        Edge<char> cc3('f', 'e', 6.3);
        Edge<char> cc4('f', 'c', 1.5);
        Edge<char> cc5('b', 'h', 8);
        Edge<char> cc6('h', 'c', 13);
        Edge<char> cc7('e', 'g', 3);
        Edge<char> cc8('c', 'g', 23);
        Edge<char> cc9('g', 'i', 8.7);
        Edge<char> cc10('h', 'd', 3);  // go back to 'd'
        Edge<char> cc11('h', 'i', 34);

        std::vector<Edge<char>> cc_edges{cc1, cc2, cc3, cc4, cc5, cc6, cc7, cc8, cc9, cc10, cc11};
        complex_char_graph.AddEdges(cc_edges);
    }


    // int graphs
    UndirectedGraph<int> simple_int_graph;
    UndirectedGraph<int> complex_int_graph;

    // char graphs
    UndirectedGraph<char> simple_char_graph;
    UndirectedGraph<char> complex_char_graph;

    // Pathfinders
    PathFinder<int> pathfinder_int;
    PathFinder<char> pathfinder_char;
};




#endif //ALGORITHMS_PATHFINDER_TEST_HPP
