//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_VERTEX_HPP
#define ALGORITHMS_VERTEX_HPP

#include <algorithm>
#include <set>
#include "edge.hpp"

namespace sangi {


    template<class T>
    class Vertex {
        template<class U> friend class Graph;
    public:
        explicit Vertex(T data) : data_(data) {}
        Vertex(const Vertex<T>& vertex);
        ~Vertex() = default;
        Vertex<T>& operator=(const Vertex<T>& vertex);


        size_t GetDegree() const                                { return in_edges_.size() + out_edges_.size(); }
        size_t GetInDegree() const                              { return in_edges_.size(); }
        size_t GetOutDegree() const                             { return out_edges_.size(); }

        const std::set<Edge<T>>& GetInEdges() const             { return in_edges_; }
        const std::set<Edge<T>>& GetOutEdges() const            { return out_edges_; }
        const T& GetData() const                                { return data_; }
    private:
        T data_;
        std::set<Edge<T>> in_edges_;
        std::set<Edge<T>> out_edges_;

        void RemoveInEdge(const Edge<T>& edge)                  { std::remove(in_edges_.begin(), in_edges_.end(), edge); }
        void RemoveOutEdge(const Edge<T>& edge)                 { std::remove(out_edges_.begin(), out_edges_.end(), edge); }

        void AddInEdge(const Edge<T>& edge)                     { in_edges_.push_back(edge); }
        void AddOutEdge(const Edge<T>& edge)                    { out_edges_.push_back(edge); }
    }; // class Vertex


    template<class T>
    Vertex<T>::Vertex(const Vertex<T>& vertex)
            : data_(vertex.data_),
              in_edges_(vertex.in_edges_),
              out_edges_(vertex.out_edges_)
    {}


    template<class T>
    Vertex<T>& Vertex<T>::operator=(const Vertex<T>& vertex) {
        if (this == &vertex) {
            return *this;
        }

        data_ = vertex.data_;
        in_edges_ = vertex.in_edges_;
        out_edges_ = vertex.out_edges_;
        return *this;
    }



} // namespace sangi


#endif //ALGORITHMS_VERTEX_HPP
