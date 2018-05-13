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
        void RemoveInEdge(const Edge<T>& edge);
        void RemoveOutEdge(const Edge<T>& edge);
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

    // Class Method Definitions

    template<class T>
    Vertex::Vertex(const Vertex<T> &vertex)
            : data_(vertex.data_),
              in_edges_(vertex.in_edges_),
              out_edges_(vertex.out_edges_)
    {}

    template<class T>
    Vertex<T>& Vertex::operator=(const Vertex<T> &vertex) {
        if (this == &vertex) {
            return *this;
        }

        data_ = vertex.data_;
        in_edges_ = vertex.in_edges_;
        out_edges_ = vertex.out_edges_;
        return *this;
    }

    template<class T>
    void Vertex::RemoveInEdge(const Edge<T> &edge) {
        std::remove(in_edges_.begin(), in_edges_.end(), edge);
    }

    template<class T>
    void Vertex::RemoveOutEdge(const Edge<T> &edge) {
        std::remove(out_edges_.begin(), out_edges_.end(), edge);
    }

} // namespace sangi


#endif //ALGORITHMS_VERTEX_HPP
