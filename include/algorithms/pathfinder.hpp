//
// Created by Amir Sangi on 2018-05-12.
//

#ifndef ALGORITHMS_PATHFINDER_HPP
#define ALGORITHMS_PATHFINDER_HPP

#include <list>
#include <queue>
#include <unordered_map>
#include <set>
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
        std::list<T> ConstructDFSPath(const std::unordered_map<T, T>& parent_map, const T& dst);
    }; // class PathFinder

    // Class Method Definitions

    template<class T>
    std::list<T> PathFinder<T>::BreadthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst) {
        using std::list;

        std::queue<list<T>> frontier;

        list<T> src_list;
        src_list.emplace_back(src);

        frontier.emplace(src_list);
        while (!frontier.empty()) {

            const list<T> path = frontier.front();
            frontier.pop();

            const T& current_vertex = path.back();
            if (current_vertex == dst) { return path; }

            // Iterate over children/adjacent vertices
            for (const T& adj : graph.GetAdjacent(current_vertex)) {
                list<T> new_path(path);
                new_path.emplace_back(adj);
                if (adj == dst) { return new_path; }
                frontier.emplace(new_path);
            }
        }

        return EmptyPath();
    }


    template<class T>
    std::list<T> PathFinder<T>::DepthFirstSearch(const UndirectedGraph<T>& graph, const T& src, const T& dst) {
        std::stack<T> frontier;
        std::set<T> visited;
        std::unordered_map<T, T> parent_map;

        frontier.emplace(src);
        while (!frontier.empty()) {
            const T& current_vertex = frontier.top();
            if (current_vertex == dst) { return ConstructDFSPath(parent_map, dst); }

            visited.insert(current_vertex);

            // Iterate over children/adjacent vertices
            for (const T& adj : graph.GetAdjacent(current_vertex)) {
                if (visited.find(adj) == visited.end()) {
                    parent_map[adj] = current_vertex;
                    frontier.emplace(adj);
                    if (adj == dst) { return ConstructDFSPath(parent_map, dst); }
                }
            }
        }

        return EmptyPath();
    }

    template<class T>
    std::list<T> PathFinder<T>::ConstructDFSPath(const std::unordered_map<T, T>& parent_map, const T& dst) {
        std::list<T> path;
        path.emplace_front(dst);

        auto search = parent_map.find(dst);

        while (search != parent_map.end()) {
            path.emplace_front(search->second);
            search = parent_map.find(search->second);
        }

        return path;
    }


} // namespace sangi

#endif //ALGORITHMS_PATHFINDER_HPP
