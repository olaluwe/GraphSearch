#ifndef ASTAR_H
#define ASTAR_H

#include <Include.h>

using namespace std;

class AStar {
  public:
    std::pair<std::vector<std::string>, int> AStarSearch(const Graph&, const std::string&, const std::string&, const std::map<std::string, int>&);
};

#endif // ASTAR_H

