#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <limits>
#include <tuple>
#include <utility>
#include <cctype>
#include <functional>

// Data structure definitions
using WeightedEdge = std::pair<int, std::string>;
typedef std::pair<std::string, int> Edge; // Neighbor, Cost
typedef std::vector<Edge> AdjList; // List of edges for each vertex
typedef std::map<std::string, AdjList> Graph; // Graph as an adjacency list
typedef std::tuple<int, int, std::string, std::vector<std::string>> Node; // f, g, current node, path

// Comparator for the priority queue used in A* search
struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        return std::get<0>(a) > std::get<0>(b); // Compare based on the f value
    }
};

#endif /*INCLUDE_H*/
