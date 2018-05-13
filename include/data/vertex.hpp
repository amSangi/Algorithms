//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_VERTEX_HPP
#define ALGORITHMS_VERTEX_HPP

#include <vector>
#include "data/edge.hpp"

using std::vector;

namespace sangi {

    template<class T>
    class Vertex {
    public:
        explicit Vertex(T data) : data_(data) {}
        Vertex(const Vertex<T>& vertex);
        ~Vertex() = default;
        Vertex<T>& operator=(const Vertex<T>& vertex);

        // Vertex Methods
        void AddInEdge(const Edge<T>& edge) { in_edges_.push_back(edge); }
        void AddOutEdge(const Edge<T>& edge) { out_edges_.push_back(edge); }
        size_t GetInEdgeCount() const { return in_edges_.size(); }
        size_t GetOutEdgeCount() const { return out_edges_.size(); }
        vector<Edge<T>> GetInEdges() const { return in_edges_; }
        vector<Edge<T>> GetOutEdges() const { return out_edges_; }
        const T& GetData() const { return data_; }
    private:
        T data_;
        vector<Edge<T>> in_edges_;
        vector<Edge<T>> out_edges_;
    }; // class Vertex

    // Class Method Implementations
    // TODO: Finish method implementations

    template<class T>
    Vertex::Vertex(const Vertex<T> &vertex)
            : data_(vertex.GetData()),
              in_edges_(vertex.GetInEdges()),
              out_edges_(vertex.GetOutEdges())
    {}

    template<class T>
    Vertex<T>& Vertex::operator=(const Vertex<T> &vertex) {}

} // namespace sangi


#endif //ALGORITHMS_VERTEX_HPP
