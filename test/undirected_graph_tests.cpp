//
// Created by Amir Sangi on 2018-05-12.
//

#include <gtest/gtest.h>
#include "undirected_graph_test.hpp"
#include "data/undirected_graph.hpp"
#include "data/edge.hpp"

using namespace sangi;

TEST_F(UndirectedGraphTest, Constructor) {
    EXPECT_EQ(4, g.GetVertexCount());
    EXPECT_EQ(4, g.GetVertices().size());
    EXPECT_EQ(0, g_empty.GetVertexCount());
    EXPECT_EQ(0, g_empty.GetVertices().size());
}

TEST_F(UndirectedGraphTest, AddVertex) {

    EXPECT_EQ(4, g.GetVertexCount());
    std::vector<int> v = g.GetVertices();
    EXPECT_EQ(4, v.size());

    // Check to see if vertices were added
    for (int i = 0; i < 4; ++i) {
        auto it = std::find(v.begin(), v.end(), i);
        EXPECT_TRUE(it != v.end());
    }
}

TEST_F(UndirectedGraphTest, AddEdge) {
    Edge<int> e1(0, 2, 3.5);

    EXPECT_EQ(0, g.GetEdges(0).size());
    EXPECT_EQ(0, g.GetEdges(2).size());

    g.AddEdge(e1);

    std::vector<Edge<int>> zero_edges = g.GetEdges(0);
    std::vector<Edge<int>> two_edges = g.GetEdges(2);

    EXPECT_EQ(1, zero_edges.size());
    EXPECT_EQ(1, two_edges.size());

    // Get both edges added
    Edge<int> zero_edge = zero_edges[0];
    Edge<int> two_edge = two_edges[0];

    // Check forward direction values
    EXPECT_EQ(0, zero_edge.GetSrc());
    EXPECT_EQ(2, zero_edge.GetDst());
    EXPECT_EQ(3.5, zero_edge.GetWeight());

    // Check reverse direction values
    EXPECT_EQ(0, two_edge.GetSrc());
    EXPECT_EQ(2, two_edge.GetDst());
    EXPECT_EQ(3.5, two_edge.GetWeight());
}

TEST_F(UndirectedGraphTest, AddVertexWithEdges) {
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

    auto begin = edges.begin();
    auto end = edges.end();

    auto it1 = std::find(begin, end, e1);
    auto it2 = std::find(begin, end, e2);
    auto it3 = std::find(begin, end, e3);

    // Check to see if edges exist
    EXPECT_TRUE(it1 != end);
    EXPECT_TRUE(it2 != end);
    EXPECT_TRUE(it3 != end);
}

TEST_F(UndirectedGraphTest, AddVertexWithOtherImplicitVertexAdd) {
    Edge<int> e1(0, 1, 5.5);
    Edge<int> e2(0, 2, 5.5);
    Edge<int> e3(0, 3, 5.5);

    // Add vertex, 5, by adding edges
    std::vector<Edge<int>> edge_vecctor{e1, e2, e3};
    g_empty.AddVertex(1, edge_vecctor);

    EXPECT_EQ(4, g_empty.GetVertexCount());

    // Check vertices after addition
    std::vector<int> v = g_empty.GetVertices();
    for (int i = 0 ; i < 4; ++i) {
        auto it = std::find(v.begin(), v.end(), i);
        EXPECT_TRUE(it != v.end());
    }
}

TEST_F(UndirectedGraphTest, RemoveVertex) {
    g.RemoveVertex(0);
    EXPECT_EQ(3, g.GetVertexCount());
    EXPECT_EQ(3, g.GetVertices().size());
}

TEST_F(UndirectedGraphTest, RemoveVertexWithEdges) {
    Edge<int> e1(0, 1, 5.5);
    Edge<int> e2(0, 2, 5.5);
    // Check only one edge added in ciruclar reference
    Edge<int> e3(0, 0, 2.3);
    Edge<int> e4(3, 0, 2.01);

    std::vector<Edge<int>> edge_vector{e1, e2, e3, e4};
    g.AddEdges(edge_vector);

    // Edge count after addition
    EXPECT_EQ(4, g.GetEdges(0).size());
    EXPECT_EQ(1, g.GetEdges(1).size());
    EXPECT_EQ(1, g.GetEdges(2).size());
    EXPECT_EQ(1, g.GetEdges(3).size());

    g.RemoveVertex(0);

    // Check edge count after removal
    EXPECT_EQ(0, g.GetEdges(1).size());
    EXPECT_EQ(0, g.GetEdges(2).size());
    EXPECT_EQ(0, g.GetEdges(3).size());
}


TEST_F(UndirectedGraphTest, AddEdgesWithImplicitVerticesAdd) {
    Edge<int> e1(0, 1, 5.5);
    Edge<int> e2(0, 2, 5.5);
    // New vertex, 5, is implicitly added
    Edge<int> e3(5, 0, 2.3);
    Edge<int> e4(3, 0, 2.01);

    // Check vertex count before edge addition
    EXPECT_EQ(4, g.GetVertexCount());
    EXPECT_EQ(4, g.GetVertices().size());

    std::vector<Edge<int>> edge_vector{e1, e2, e3, e4};
    g.AddEdges(edge_vector);

    // Check vertex count after edge addition
    EXPECT_EQ(5, g.GetVertexCount());
    EXPECT_EQ(5, g.GetVertices().size());

    // Edge counts after addition
    EXPECT_EQ(4, g.GetEdges(0).size());
    EXPECT_EQ(1, g.GetEdges(1).size());
    EXPECT_EQ(1, g.GetEdges(2).size());
    EXPECT_EQ(1, g.GetEdges(3).size());
    EXPECT_EQ(1, g.GetEdges(5).size());

    g.RemoveVertex(0);

    // Check edge counts after removal
    EXPECT_EQ(0, g.GetEdges(1).size());
    EXPECT_EQ(0, g.GetEdges(2).size());
    EXPECT_EQ(0, g.GetEdges(3).size());
    EXPECT_EQ(0, g.GetEdges(5).size());

}

TEST_F(UndirectedGraphTest, RemoveEdge) {
    Edge<int> e1(0, 1, 5.5);

    // Check edges before addition
    EXPECT_EQ(0, g.GetEdges(0).size());
    EXPECT_EQ(0, g.GetEdges(1).size());

    g.AddEdge(e1);

    // Check edges after addition
    EXPECT_EQ(1, g.GetEdges(0).size());
    EXPECT_EQ(1, g.GetEdges(1).size());

    g.RemoveEdge(e1);

    // Check edges after removal
    EXPECT_EQ(0, g.GetEdges(0).size());
    EXPECT_EQ(0, g.GetEdges(1).size());
}

TEST_F(UndirectedGraphTest, GetAdjacent) {
    Edge<int> e1{0, 1, 5.5};
    Edge<int> e2{0, 2, 3.5};
    Edge<int> e3{3, 0, 2.2};

    g.AddEdge(e1);
    g.AddEdge(e2);
    g.AddEdge(e3);

    std::vector<int> adj_vertices = g.GetAdjacent(0);
    EXPECT_EQ(3, adj_vertices.size());

    // Check correct values added
    auto begin = adj_vertices.begin();
    auto end = adj_vertices.end();

    auto it1 = std::find(begin, end, 1);
    auto it2 = std::find(begin, end, 2);
    auto it3 = std::find(begin, end, 3);

    EXPECT_TRUE(it1 != end);
    EXPECT_TRUE(it2 != end);
    EXPECT_TRUE(it3 != end);
}


