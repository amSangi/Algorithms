//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_PATHFINDER_HPP
#define ALGORITHMS_PATHFINDER_HPP

#include <list>
#include <queue>
#include <stack>
#include "data/undirected_graph.hpp"

namespace sangi {

    template<class T>
    class PathFinder {
    public:
        PathFinder() = default;
        ~PathFinder() = default;

        // Uninformed Searches
        std::list<T> BreadthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst);
        std::list<T> DepthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst);

    private:

        inline std::list<T> EmptyPath() { return std::list<T>(); }
    }; // class PathFinder

    // Class Method Definitions

    template<class T>
    std::list<T> PathFinder<T>::BreadthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst) {
        using std::queue;
        using std::list;

        queue<list<T>> frontier;

        list<T> src_list;
        src_list.push_back(src);

        frontier.push(src_list);
        while (!frontier.empty()) {

            const list<T> path = frontier.front();
            frontier.pop();

            const T& current_vertex = path.back();
            if (current_vertex == dst) { return path; }

            auto adj_ = graph.GetAdjacent(current_vertex);
            for (const T& adj : graph.GetAdjacent(current_vertex)) {
                list<T> new_path(path);
                new_path.push_back(adj);
                if (adj == dst) { return new_path; }
                frontier.push(new_path);
            }
        }

        return EmptyPath();
    }


    template<class T>
    std::list<T> PathFinder<T>::DepthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst) {
        // TODO: Finish Impl
        return EmptyPath();
    }


} // namespace sangi

#endif //ALGORITHMS_PATHFINDER_HPP
