#include <AStar.h>

using namespace std;

std::pair<std::vector<std::string>, int> AStar::AStarSearch(const Graph& graph, const std::string& start, const std::string& goal, const std::map<std::string, int>& heuristic) 
{
  std::priority_queue<Node, std::vector<Node>, Compare> open_list;
  std::map<std::string, int> costSoFar;
  std::map<std::string, std::string> cameFrom;

  open_list.push(std::make_tuple(heuristic.at(start), 0, start, std::vector<std::string>{start}));
  costSoFar[start] = 0;

  while (!open_list.empty()) {
      auto [f, g, current, path] = open_list.top();
      open_list.pop();

      if (current == goal) {
          return {path, costSoFar[goal]};
      }

      for (const auto& [neighbor, cost] : graph.at(current)) {
          int newCost = g + cost;
          if (!costSoFar.count(neighbor) || newCost < costSoFar[neighbor]) {
              costSoFar[neighbor] = newCost;
              int priority = newCost + heuristic.at(neighbor);
              std::vector<std::string> newPath = path;
              newPath.push_back(neighbor);
              open_list.push(std::make_tuple(priority, newCost, neighbor, newPath));
              cameFrom[neighbor] = current;
          }
      }
  }

  // If the goal is not reachable, return an empty path and a cost of -1 (or another indicator value)
  return {std::vector<std::string>(), -1};
}
