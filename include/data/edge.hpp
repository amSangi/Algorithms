//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_EDGE_HPP
#define ALGORITHMS_EDGE_HPP


namespace sangi {

    template<class T> class Vertex;

    template<class T>
    class Edge {
    public:
        Edge(Vertex<T>& src, Vertex<T>& dst, const double weight);
        Edge(const Edge<T>& edge);
        ~Edge() = default;
        Edge<T>& operator=(const Edge<T>& edge);

        const Vertex<T>* GetSrc() const                       { return src_; }
        const Vertex<T>* GetDst() const                       { return dst_; }
        double GetWeight() const                              { return weight_; }
    private:
        Vertex<T>* src_;
        Vertex<T>* dst_;
        double weight_;
    }; // class Edge


    template<class T>
    Edge<T>::Edge(Vertex<T>& src, Vertex<T>& dst,
               const double weight)
            : src_(&src),
              dst_(&dst),
              weight_(weight) {}


    template<class T>
    Edge<T>::Edge(const Edge<T>& edge)
            : src_(edge.src_),
              dst_(edge.dst_),
              weight_(edge.weight_)
    {}


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
