//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <set>
#include "edge.hpp"
#include "vertex.hpp"

using std::set;

namespace sangi {

    template <class T>
    class Graph {
    public:
        explicit Graph(const Vertex<T>& root) : root_(root) {}
        Graph(const Vertex<T>& root,
              const set<Edge<T>>& edges,
              const set<Vertex<T>>& vertices);
        Graph(const Graph<T>& graph);
        ~Graph() = default;
        Graph<T>& operator=(const Graph<T>& graph);

        // Graph Methods
        void AddVertex(const Vertex<T>& value);
        void RemoveVertex(const T& value);
        void RemoveVertex(const Vertex<T>& vertex);
        void AddEdge(const T& src, const T& dst, double weight);
        void RemoveEdge(const Edge<T>& edge);
        size_t GetVertexCount() const                                   { return vertices_.size(); }
        size_t GetEdgeCount() const                                     { return edges_.size(); }
        set<Edge<T>> GetEdges() const                                   { return edges_; }
        set<Vertex<T>> GetVertices() const                              { return vertices_; }
        Vertex<T> GetRoot() const                                          { return root_; }
    private:
        Vertex<T> root_;
        set<Edge<T>> edges_;
        set<Vertex<T>> vertices_;

    }; // class Graph

    // Class Method Definitions

    template <class T>
    Graph<T>::Graph(const Graph<T>& graph)
            : root_(graph.root_),
              edges_(graph.edges_),
              vertices_(graph.vertices_)
    {}


    template<class T>
    Graph<T>::Graph(const Vertex<T>& root,
                 const set<Edge<T>>& edges,
                 const set<Vertex<T>>& vertices)
            : root_(root),
              edges_(edges),
              vertices_(vertices)
    {}


    template <class T>
    Graph<T>& Graph<T>::operator=(const Graph<T>& graph) {
        if (this == &graph) {
            return *this;
        }

        root_ = graph.root_;
        edges_ = graph.edges_;
        vertices_ = graph.vertices_;
        return *this;
    }


    template<class T>
    void Graph<T>::AddVertex(const Vertex<T>& value) {
        Vertex<T> v(value);
        vertices_.insert(value);
    }


    template<class T>
    void Graph<T>::RemoveVertex(const T& value) {
        Vertex<T> v(value);
        std::remove(vertices_.begin(), vertices_.end(), v);
    }


    template<class T>
    void Graph<T>::RemoveVertex(const Vertex<T>& vertex) {
        std::remove(vertices_.begin(), vertices_.end(), vertex);
    }


    template<class T>
    void Graph<T>::AddEdge(const T& src, const T& dst, double weight) {
        Edge<T> e(src, dst, weight);
        edges_.insert(e);
    }


    template<class T>
    void Graph<T>::RemoveEdge(const Edge<T>& edge) {
        std::remove(edges_.begin(), edges_.end(), edge);
    }

} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
