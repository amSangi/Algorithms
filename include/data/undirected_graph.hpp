//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <unordered_map>
#include "edge.hpp"

namespace sangi {

    template <class T>
    class UndirectedGraph {
        typedef typename std::vector<T> VertexVector;
        typedef typename std::vector<Edge<T>> EdgeVector;
        typedef typename std::unordered_map<T, EdgeVector> AdjList;
    public:
        UndirectedGraph() = default;

        void AddVertex(const T vertex)                          { adj_list_[vertex]; }

        void AddVertex(const T vertex,
                       const EdgeVector edge_vector) {
            adj_list_[vertex];
            AddEdges(edge_vector);
        }


        void RemoveVertex(const T vertex) {
            auto it = adj_list_.find(vertex);

            if (it != adj_list_.end()) {
                // Remove vertex and its edge list
                adj_list_.erase(it);

                // Remove edges connecting to vertex
                RemoveConnectedEdges(vertex);
            }
        }

        void AddEdge(const Edge<T> edge) {
            T src = edge.GetSrc();
            T dst = edge.GetDst();

            adj_list_[src].push_back(edge);
            if (src != dst) {
                adj_list_[dst].push_back(edge);
            }
        }

        void AddEdges(const EdgeVector edge_vector) {
            for (const Edge<T>& edge : edge_vector) {
                AddEdge(edge);
            }
        }

        void RemoveEdge(const Edge<T> edge) {

            for (auto&[v, edge_vector] : adj_list_) {
                edge_vector.erase(
                        std::remove(
                                edge_vector.begin(),
                                edge_vector.end(),
                                edge),
                        edge_vector.end());
            }
        }

        const VertexVector GetAdjacent(const T& vertex) const {
            VertexVector v;
            auto search = adj_list_.find(vertex);
            if (search == adj_list_.end()) { return v; }


            for (const Edge<T>& edge : search->second) {
                T src = edge.GetSrc();
                T dst = edge.GetDst();
                if (src == vertex) { v.push_back(dst); }
                if (dst == vertex) { v.push_back(src); }
            }

            return v;
        }

        const VertexVector GetVertices() const {
            VertexVector vec;

            for (auto&[v, edge_vector] : adj_list_) {
                vec.push_back(v);
            }

            return vec;
        }

        const EdgeVector& GetEdges(const T& vertex)                     { return adj_list_[vertex]; }

        size_t GetVertexCount() const                                   { return adj_list_.size(); }
    private:
        AdjList adj_list_;

        void RemoveConnectedEdges(const T& vertex) {

            auto IsConnectedEdge = [vertex](const Edge<T>& edge) { return edge.GetSrc() == vertex
                                                                   || edge.GetDst() == vertex; };

            // Remove all edges connected to vertex
            for (auto&[v, edge_vector] : adj_list_) {

                edge_vector.erase(
                        std::remove_if(
                                edge_vector.begin(),
                                edge_vector.end(),
                                IsConnectedEdge),
                        edge_vector.end());
            }
        }
    }; // class UndirectedGraph


} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
