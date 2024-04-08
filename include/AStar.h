#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <tuple>

// Data structure definitions
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

// Function prototypes
Graph createGraph();
std::map<std::string, int> createHeuristic();
std::vector<std::string> a_star_search(const Graph& graph, const std::string& start, const std::string& goal, const std::map<std::string, int>& heuristic);

#endif // ASTAR_H

