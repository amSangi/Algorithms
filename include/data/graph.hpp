//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <vector>
#include <cstddef>
#include "data/edge.hpp"
#include "vertex.hpp"

using std::vector;

namespace sangi {

    template <class T>
    class Graph {
    public:
        explicit Graph(Vertex<T> root) : root_(root) {}
        Graph(const Graph<T>& graph);
        ~Graph() = default;
        Graph<T>& operator=(const Graph<T>& graph);

        // Graph Methods
        Vertex<T> AddVertex(T value);
        void RemoveVertex(T value);
        void RemoveVertex(Vertex<T> vertex);
        Edge<T> AddEdge(T src, T dst, double weight);
        void RemoveEdge(Edge<T> edge);
        size_t GetVertexCount() const { return vertices_.size(); }
        size_t GetEdgeCount() const { return edges_.size(); }
        vector<Edge<T>> GetEdges() const { return edges_; }
        vector<Vertex<T>> GetVertices() const { return vertices_; }
        Vertex GetRoot() const { return root_; }
    private:
        Vertex<T> root_;
        vector<Edge<T>> edges_;
        vector<Vertex<T>> vertices_;

    }; // class Graph

    // Class Method Definitions

    template <class T>
    Graph::Graph(const Graph<T>& graph)
            : root_(graph.root_),
              edges_(graph.edges_),
              vertices_(graph.vertices_)
    {}


    template <class T>
    Graph<T>& Graph::operator=(const Graph<T>& graph) {
        if (this == &graph) {
            return *this;
        }

        root_ = graph.root_;
        edges_ = graph.edges_;
        vertices_ = graph.vertices_;
        return *this;
    }


    template<class T>
    Vertex<T> Graph::AddVertex(T value) {
        Vertex<T> v(value);
        vertices_.push_back(v);
    }


    template<class T>
    void Graph::RemoveVertex(T value) {
        Vertex<T> v(value);
        std::remove(vertices_.begin(), vertices_.end(), v);
    }


    template<class T>
    void Graph::RemoveVertex(Vertex<T> vertex) {
        std::remove(vertices_.begin(), vertices_.end(), vertex);
    }


    template<class T>
    Edge<T> Graph::AddEdge(T src, T dst, double weight) {
        Edge<T> e(src, dst, weight);
        edges_.push_back(e);
    }


    template<class T>
    void Graph::RemoveEdge(Edge<T> edge) {
        std::remove(edges_.begin(), edges_.end(), edge);
    }
    
} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
