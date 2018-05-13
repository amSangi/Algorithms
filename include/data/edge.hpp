//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_EDGE_HPP
#define ALGORITHMS_EDGE_HPP

#include "vertex.hpp"

namespace sangi {

    template<class T>
    class Edge {
    public:
        Edge(const Vertex<T>& src,
             const Vertex<T>& dst,
             const double weight);
        Edge(const Edge<T>& edge);
        ~Edge();
        Edge<T>& operator=(const Edge<T>& edge);

        // Edge Methods
        const Vertex<T> GetSrc() const                       { return src_; }
        const Vertex<T> GetDst() const                       { return dst_; }
        double GetWeight() const                             { return weight_; }
    private:
        Vertex<T> src_;
        Vertex<T> dst_;
        double weight_;
    }; // class Edge

    // Class Method Definitions

    template<class T>
    Edge<T>::Edge(const Vertex<T>& src,
               const Vertex<T>& dst,
               const double weight)
            : src_(src),
              dst_(dst),
              weight_(weight)
    {
        src_.AddOutEdge(*this);
        dst_.AddInEdge(*this);
    }


    template<class T>
    Edge<T>::Edge(const Edge<T>& edge)
            : src_(edge.src_),
              dst_(edge.dst_),
              weight_(edge.weight_)
    {}


    template<class T>
    Edge<T>::~Edge() {
        src_.RemoveOutEdge(*this);
        dst_.RemoveInEdge(*this);
    }


    template<class T>
    Edge<T>& Edge<T>::operator=(const Edge<T>& edge) {
        if (this == &edge) {
            return *this;
        }

        src_ = edge.src_;
        dst_ = edge.dst_;
        weight_ = edge.weight_;
        return *this;
    }

} // namespace sangi

#endif //ALGORITHMS_EDGE_HPP
