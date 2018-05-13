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

    // TODO: Finish class implementation
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




} // namespace sangi

#endif //ALGORITHMS_PATHFINDER_HPP
