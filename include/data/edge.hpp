//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_EDGE_HPP
#define ALGORITHMS_EDGE_HPP


namespace sangi {

    template<class T>
    class Edge {
    public:
        Edge(const T src, const T dst, const double weight)     : src_(src), dst_(dst), weight_(weight) {}

        bool operator <(const Edge<T>& edge)                    { return weight_ < edge.weight_; }

        bool operator ==(const Edge<T>& edge)                   { return src_ == edge.src_ && dst_ == edge.dst_; }

        const T& GetSrc() const                                 { return src_; }
        const T& GetDst() const                                 { return dst_; }
        double GetWeight() const                                { return weight_; }
    private:
        const T src_;
        const T dst_;
        double weight_;
    }; // class Edge

} // namespace sangi

#endif //ALGORITHMS_EDGE_HPP
