//
// Created by Amir Sangi on 2018-05-12.
//

#include <gtest/gtest.h>
#include "graph_test.hpp"
#include "data/graph.hpp"
#include "data/edge.hpp"

using namespace sangi;

TEST_F(GraphTest, TestConstructor) {
    EXPECT_EQ(4, g.GetVertexCount());
    EXPECT_EQ(4, g.GetVertices().size());
    EXPECT_EQ(0, g_empty.GetVertexCount());
    EXPECT_EQ(0, g_empty.GetVertices().size());
}

TEST_F(GraphTest, AddVertex) {

    EXPECT_EQ(4, g.GetVertexCount());
    std::vector<int> v = g.GetVertices();
    EXPECT_EQ(4, v.size());

    // Check to see if vertices were added
    for (int i = 0; i < 4; ++i) {
        auto it = std::find(v.begin(), v.end(), i);
        EXPECT_TRUE(it != v.end());
    }
}

TEST_F(GraphTest, AddVertexWithEdges) {
    Edge<int> e1(5, 1, 5.5);
    Edge<int> e2(5, 2, 3.3);
    Edge<int> e3(5, 3, 2.2);

    std::vector<Edge<int>> edge_vector{e1, e2, e3};
    g.AddVertex(5, edge_vector);

    EXPECT_EQ(5, g.GetVertexCount());
    std::vector<int> v = g.GetVertices();
    EXPECT_EQ(5, v.size());

    // Check to see if edges were added
    std::vector<Edge<int>> edges = g.GetEdges(5);
    EXPECT_EQ(3, edges.size());
    auto it1 = std::find(edges.begin(), edges.end(), e1);
    auto it2 = std::find(edges.begin(), edges.end(), e2);
    auto it3 = std::find(edges.begin(), edges.end(), e3);

    EXPECT_TRUE(it1 != edges.end());
    EXPECT_TRUE(it2 != edges.end());
    EXPECT_TRUE(it3 != edges.end());
}

TEST_F(GraphTest, AddVertexWithOtherImplicitVertexAdd) {}

TEST_F(GraphTest, RemoveVertex) {}

TEST_F(GraphTest, AddEdge) {}

TEST_F(GraphTest, AddEdgeWithImplicitVertexAdd) {}

TEST_F(GraphTest, AddMultipleEdges) {}

TEST_F(GraphTest, AddEdgesWithImplicitVerticesAdd) {}

TEST_F(GraphTest, RemoveEdge) {}

TEST_F(GraphTest, GetAdjacent) {}


