//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_PATHFINDER_HPP
#define ALGORITHMS_PATHFINDER_HPP

#include <vector>
#include <list>
#include "data/graph.hpp"
#include "data/vertex.hpp"

using std::vector;
using std::list;

namespace sangi {

    template<class T>
    class PathFinder {
    public:
        // Uninformed Searches
        list<Vertex<T>> BreadthFirstSearch(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> DepthFirstSearch(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> BranchAndBound(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> IterativeDeepening(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> BidirectionalSearch(const Graph<T>& graph, const Vertex<T>& node);

        // Informed Searches
        list<Vertex<T>> BestFirstSearch(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> ASharp(const Graph<T>& graph, const Vertex<T>& node);
        list<Vertex<T>> GeneticSearch(const Graph<T>& graph, const Vertex<T>& node);

    }; // class PathFinder

    // Class Method Definitions

    template<class T>
    list<Vertex<T>> PathFinder::BreadthFirstSearch(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::DepthFirstSearch(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::BranchAndBound(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::IterativeDeepening(const Graph<T> &graph, const Vertex<T> &node){
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::BidirectionalSearch(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::BestFirstSearch(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::ASharp(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<Vertex<T>> PathFinder::GeneticSearch(const Graph<T>& graph, const Vertex<T>& node) {
        // TODO: Finish Impl
    }

} // namespace sangi

#endif //ALGORITHMS_PATHFINDER_HPP
