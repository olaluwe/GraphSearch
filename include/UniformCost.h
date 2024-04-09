#ifndef UNIFORMCOST_H
#define GRAPH_H

#include <Include.h>

using namespace std;

class UniformCost
{
  public:
    std::pair<std::vector<std::string>, int> UniformCostSearch(const Graph&, const std::string&, const std::string&);
};

#endif // GRAPH_H
