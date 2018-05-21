//
// Created by Amir Sangi on 2018-05-20.
//

#ifndef ALGORITHMS_GRAPH_TEST_HPP
#define ALGORITHMS_GRAPH_TEST_HPP

#include <gtest/gtest.h>
#include "data/graph.hpp"

using namespace sangi;

class GraphTest : public ::testing::Test {
protected:

    virtual void SetUp() {
        g.AddVertex(0);
        g.AddVertex(1);
        g.AddVertex(2);
        g.AddVertex(3);
    }

    Graph<int> g;
    Graph<int> g_empty;

};

#endif //ALGORITHMS_GRAPH_TEST_HPP
