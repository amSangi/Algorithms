//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_VERTEX_HPP
#define ALGORITHMS_VERTEX_HPP

#include <set>

using std::set;

namespace sangi {

    // Edge forward declaration
    template<class T>
    class Edge;

    template<class T>
    class Vertex {
    public:
        explicit Vertex(T data) : data_(data) {}
        Vertex(const Vertex<T>& vertex);
        ~Vertex() = default;
        Vertex<T>& operator=(const Vertex<T>& vertex);

        // Vertex Methods
        void RemoveInEdge(const Edge<T>& edge);
        void RemoveOutEdge(const Edge<T>& edge);
        void AddInEdge(const Edge<T>& edge)                 { in_edges_.insert(edge); }
        void AddOutEdge(const Edge<T>& edge)                { out_edges_.insert(edge); }
        size_t GetInEdgeCount() const                       { return in_edges_.size(); }
        size_t GetOutEdgeCount() const                      { return out_edges_.size(); }
        set<Edge<T>> GetInEdges() const                     { return in_edges_; }
        set<Edge<T>> GetOutEdges() const                    { return out_edges_; }
        const T& GetData() const                            { return data_; }
    private:
        T data_;
        set<Edge<T>> in_edges_;
        set<Edge<T>> out_edges_;
    }; // class Vertex

    // Class Method Definitions

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


    template<class T>
    void Vertex<T>::RemoveInEdge(const Edge<T>& edge) {
        std::remove(in_edges_.begin(), in_edges_.end(), edge);
    }


    template<class T>
    void Vertex<T>::RemoveOutEdge(const Edge<T>& edge) {
        std::remove(out_edges_.begin(), out_edges_.end(), edge);
    }

} // namespace sangi


#endif //ALGORITHMS_VERTEX_HPP
