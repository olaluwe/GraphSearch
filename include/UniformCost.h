// RomaniaMap.h
#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include <vector>

typedef std::pair<std::string, int> Edge; // Neighbor, Cost
typedef std::vector<Edge> AdjList; // List of edges
typedef std::map<std::string, AdjList> Graph; // Graph as an adjacency list

Graph createGraph();

#endif // GRAPH_H
