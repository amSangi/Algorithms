//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <vector>
#include <cstddef>
#include "edge.hpp"
#include "vertex.hpp"

using std::vector;

namespace sangi {

    template <class T>
    class Graph {
    public:
        explicit Graph(Vertex<T> root) : root_(root) {}
        explicit Graph(const Graph<T>& graph);
        ~Graph() = default;
        Graph<T>& operator=(const Graph<T>& graph);

        // TODO: Return references or values?
        // Graph Methods
        Vertex<T>& AddVertex(T value);
        void RemoveVertex(T value);
        Edge<T>& AddEdge(T src, T dst);
        void RemoveEdge(Edge<T> edge);
        size_t GetVertexCount() const { return vertices_.size(); }
        size_t GetEdgeCount() const { return edges_.size(); }
        vector<Edge<T>>& GetEdges() const { return edges_; }
        vector<Vertex<T>>& GetVertices() const { return vertices_; }
        Vertex& GetRoot() const { return root_; }
    private:
        Vertex<T> root_;
        vector<Edge<T>> edges_;
        vector<Vertex<T>> vertices_;

    }; // class Graph

    // Class Method Implementations
    // TODO: Finish method implementations

    template <class T>
    Graph::Graph(const Graph<T>& graph)
            : root_(graph.GetRoot()),
              edges_(graph.GetEdges()),
              vertices_(graph.GetVertices())
    {}

    template <class T>
    Graph<T>& Graph::operator=(const Graph<T>& graph) {}

    template<class T>
    Vertex<T>& Graph::AddVertex(T value) {}

    template<class T>
    void Graph::RemoveVertex(T value) {}

    template<class T>
    Edge<T>& Graph::AddEdge(T src, T dst) {}

    template<class T>
    void Graph::RemoveEdge(sangi::Edge<T> edge) {}


} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
