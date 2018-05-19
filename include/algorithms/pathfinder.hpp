//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_PATHFINDER_HPP
#define ALGORITHMS_PATHFINDER_HPP

#include <vector>
#include <list>
#include "data/graph.hpp"

using std::vector;
using std::list;

namespace sangi {

    template<class T>
    class PathFinder {
    public:
        // Uninformed Searches
        list<T> BreadthFirstSearch(const Graph<T>& graph, const T& node);
        list<T> DepthFirstSearch(const Graph<T>& graph, const T& node);
        list<T> BranchAndBound(const Graph<T>& graph, const T& node);
        list<T> IterativeDeepening(const Graph<T>& graph, const T& node);
        list<T> BidirectionalSearch(const Graph<T>& graph, const T& node);

        // Informed Searches
        list<T> BestFirstSearch(const Graph<T>& graph, const T& node);
        list<T> ASharp(const Graph<T>& graph, const T& node);
        list<T> GeneticSearch(const Graph<T>& graph, const T& node);

    }; // class PathFinder

    // Class Method Definitions

    template<class T>
    list<T> PathFinder::BreadthFirstSearch(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::DepthFirstSearch(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::BranchAndBound(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::IterativeDeepening(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::BidirectionalSearch(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::BestFirstSearch(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::ASharp(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }


    template<class T>
    list<T> PathFinder::GeneticSearch(const Graph<T>& graph, const T& node) {
        // TODO: Finish Impl
    }

} // namespace sangi

#endif //ALGORITHMS_PATHFINDER_HPP
