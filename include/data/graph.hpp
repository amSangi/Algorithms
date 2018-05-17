//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <set>
#include "edge.hpp"
#include "vertex.hpp"

namespace sangi {

    template <class T>
    class Graph {
        using iter_t = typename std::vector<T>::iterator;
    public:
        Graph() = default;
        Graph(const std::vector<Edge<T>>& edges,
              const std::vector<Vertex<T>>& vertices);
        Graph(const Graph<T>& graph);
        ~Graph() = default;
        Graph<T>& operator=(const Graph<T>& graph);

        void RemoveVertex(const Vertex<T>& vertex);
        void AddVertex(const Vertex<T>& value);

        void RemoveEdge(const Edge<T>& edge);
        void AddEdge(const Edge<T>& edge);

        size_t GetVertexCount() const                               { return vertices_.size(); }
        size_t GetEdgeCount() const                                 { return edges_.size(); }

        const std::vector<Edge<T>>& GetEdges() const                { return edges_; }
        const std::vector<Vertex<T>>& GetVertices() const           { return vertices_; }
    private:
        std::vector<Edge<T>> edges_;
        std::vector<Vertex<T>> vertices_;

    }; // class Graph


    template <class T>
    Graph<T>::Graph(const Graph<T>& graph)
            : edges_(graph.edges_),
              vertices_(graph.vertices_)
    {}


    template<class T>
    Graph<T>::Graph(const std::vector<Edge<T>>& edges,
                    const std::vector<Vertex<T>>& vertices)
            : edges_(edges),
              vertices_(vertices)
    {}


    template <class T>
    Graph<T>& Graph<T>::operator=(const Graph<T>& graph) {
        if (this == &graph) {
            return *this;
        }

        edges_ = graph.edges_;
        vertices_ = graph.vertices_;
        return *this;
    }


    template<class T>
    void Graph<T>::AddVertex(const Vertex<T>& value) {
        // TODO: Finish Impl - add unique vertices
    }


    template<class T>
    void Graph<T>::RemoveVertex(const Vertex<T>& vertex) {
        // TODO: Finish Impl - remove all edges with vertex
    }


    template<class T>
    void Graph<T>::AddEdge(const Edge<T>& edge) {
        // TODO: Finish Impl - add unique edges
    }


    template<class T>
    void Graph<T>::RemoveEdge(const Edge<T>& edge) {
        // TODO: Finish Impl - remove edge from all vertices
    }

} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
