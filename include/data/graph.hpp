//
// Created by Amir Sangi on 2018-05-09.
//

#ifndef ALGORITHMS_GRAPH_HPP
#define ALGORITHMS_GRAPH_HPP

#include <unordered_map>
#include "edge.hpp"

namespace sangi {

    template <class T>
    class Graph {
        typedef typename std::vector<T> VertexVector;
        typedef typename std::vector<Edge<T>> EdgeVector;
        typedef typename std::unordered_map<T, EdgeVector> AdjList;
    public:
        Graph() = default;

        bool AddVertex(const T vertex) {
            adj_list[vertex];
        }

        bool AddVertex(const T vertex, const EdgeVector edge_container) {
            adj_list.insert(vertex, edge_container);
        }

        void RemoveVertex(const T vertex);

        bool AddEdge(const Edge<T> edge);
        void RemoveEdge(const Edge<T> edge);

        const EdgeVector GetAdjacent(const T& vertex) const;

        const EdgeVector& GetEdges(const T& vertex) const;
        const VertexVector& GetVertices() const;

        size_t GetVertexCount() const                                   { return adj_list.size(); }
    private:
        AdjList adj_list;
    }; // class Graph


} // namespace sangi

#endif //ALGORITHMS_GRAPH_HPP
