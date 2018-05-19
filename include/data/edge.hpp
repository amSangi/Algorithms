//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_EDGE_HPP
#define ALGORITHMS_EDGE_HPP


namespace sangi {

    template<class T> class Vertex;

    template<class T>
    class Edge {
        template<class U> friend class Graph;
    public:
        Edge(Vertex<T>& src, Vertex<T>& dst, const double weight) : src_(src), dst_(dst), weight_(weight) {}

        const Vertex<T>& GetSrc() const                       { return src_; }
        const Vertex<T>& GetDst() const                       { return dst_; }
        double GetWeight() const                              { return weight_; }
    private:
        Vertex<T>& src_;
        Vertex<T>& dst_;
        double weight_;
    }; // class Edge

} // namespace sangi

#endif //ALGORITHMS_EDGE_HPP
