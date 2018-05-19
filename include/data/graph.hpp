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
        using v_iter = typename std::set<Vertex<T>>::iterator;
        using e_iter = typename std::set<Edge<T>>::iterator;
    public:
        Graph() = default;

        bool AddVertex(const Vertex<T>& vertex);
        bool RemoveVertex(const Vertex<T>& vertex);

        bool AddEdge(const Edge<T>& edge);
        bool RemoveEdge(const Edge<T>& edge);

        size_t GetVertexCount() const                               { return vertices_.size(); }
        size_t GetEdgeCount() const                                 { return edges_.size(); }

        const std::set<Edge<T>>& GetEdges() const                   { return edges_; }
        const std::set<Vertex<T>>& GetVertices() const              { return vertices_; }
    private:
        std::set<Edge<T>> edges_;
        std::set<Vertex<T>> vertices_;
    }; // class Graph


    template<class T>
    bool Graph<T>::AddVertex(const Vertex<T> &vertex){
        return vertices_.insert(vertex).second;
    }


    template<class T>
    bool Graph<T>::RemoveVertex(const Vertex<T>& vertex) {
        v_iter it = vertices_.find(vertex);

        bool contains_vertex = it != vertices_.end();

        // Remove all edges connected to vertex
        if (contains_vertex) {
            Vertex<T> v = *it;

            for (auto& e : v.in_edges_) {
                e.src_.out_edges_.erase(e);
            }

            for (auto& e : v.out_edges_) {
                e.dst_.in_edges_.erase(e);
            }

            v.in_edges_.clear();
            v.out_edges_.clear();
        }

        return contains_vertex;
    }


    template<class T>
    bool Graph<T>::AddEdge(const Edge<T>& edge) {
        bool added = edges_.insert(edge).second;

        if (added) {
            edge.src_.AddOutEdge(edge);
            edge.dst_.AddInEdge(edge);
        }

        return added;
    }


    template<class T>
    bool Graph<T>::RemoveEdge(const Edge<T>& edge) {
        e_iter it = edges_.find(edge);

        bool contains_edge = (it != edges_.end());

        if (contains_edge) {
            edge.src_.out_edges_.erase(edge);
            edge.dst_.in_edges_.erase(edge);
            edges_.erase(it);
        }

        return contains_edge;
    }


} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
