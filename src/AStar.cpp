#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>

using namespace std;

typedef pair<string, int> Edge; // Neighbor, Cost
typedef vector<Edge> AdjList; // List of edges
typedef map<string, AdjList> Graph; // Graph as an adjacency list
typedef tuple<int, int, string, vector<string>> Node; // f, g, current, path

// Comparator for priority_queue, compares two nodes based on their f value
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return get<0>(a) > get<0>(b); // Compare based on f value
    }
};

const std::vector<std::string> CITIES = {
  "Arad",
  "Bucharest",
  "Craiova",
  "Drobeta",
  "Eforie",
  "Fagaras",
  "Giurgiu",
  "Hirsova",
  "Iasi",
  "Lugoj",
  "Mehadia",
  "Neamt",
  "Oradea",
  "Pitesti",
  "Rimnicu Vilcea",
  "Sibiu",
  "Timisoara",
  "Urziceni",
  "Vaslui",
  "Zerind"
};

Graph romaniaMap = {
  {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
  {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
  {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
  {"Sibiu", {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
  {"Rimnicu Vilcea", {{"Sibiu", 80}, {"Pitesti", 97}, {"Craiova", 146}}},
  {"Craiova", {{"Rimnicu Vilcea", 146}, {"Pitesti", 138}, {"Drobeta", 120}}},
  {"Drobeta", {{"Craiova", 120}, {"Mehadia", 75}}},
  {"Mehadia", {{"Drobeta", 75}, {"Lugoj", 70}}},
  {"Lugoj", {{"Mehadia", 70}, {"Timisoara", 111}}},
  {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
  {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}},
  {"Pitesti", {{"Craiova", 138}, {"Rimnicu Vilcea", 97}, {"Bucharest", 101}}},
  {"Bucharest", {{"Fagaras", 211}, {"Pitesti", 101}, {"Giurgiu", 90}, {"Urziceni", 85}}},
  {"Giurgiu", {{"Bucharest", 90}}},
  {"Urziceni", {{"Bucharest", 85}, {"Vaslui", 142}, {"Hirsova", 98}}},
  {"Hirsova", {{"Urziceni", 98}, {"Eforie", 86}}},
  {"Eforie", {{"Hirsova", 86}}},
  {"Vaslui", {{"Urziceni", 142}, {"Iasi", 92}}},
  {"Iasi", {{"Vaslui", 92}, {"Neamt", 87}}},
  {"Neamt", {{"Iasi", 87}}}
};

map<string, int> heuristic = {
  {"Arad", 366},
  {"Bucharest", 0},
  {"Craiova", 160},
  {"Drobeta", 242},
  {"Eforie", 161},
  {"Fagaras", 176},
  {"Giurgiu", 77},
  {"Hirsova", 151},
  {"Iasi", 226},
  {"Lugoj", 244},
  {"Mehadia", 241},
  {"Neamt", 234},
  {"Oradea", 380},
  {"Pitesti", 100},
  {"Rimnicu Vilcea", 193},
  {"Sibiu", 253},
  {"Timisoara", 329},
  {"Urziceni", 80},
  {"Vaslui", 199},
  {"Zerind", 174}
  };

vector<string> a_star_search_without_cost(const Graph& graph, const string& start, const string& goal, const map<string, int>& heuristic) {
  priority_queue<Node, vector<Node>, Compare> open_list;
  map<string, int> costSoFar;
  map<string, string> cameFrom;

  open_list.push(make_tuple(heuristic.at(start), 0, start, vector<string>{start}));

  while (!open_list.empty()) {
      auto [f, g, current, path] = open_list.top();
      open_list.pop();

      if (current == goal) {
          return path;
      }

      for (auto& [neighbor, cost] : graph.at(current)) {
          int newCost = g + cost;
          if (!costSoFar.count(neighbor) || newCost < costSoFar[neighbor]) {
              costSoFar[neighbor] = newCost;
              int priority = newCost + heuristic.at(neighbor);
              vector<string> newPath = path;
              newPath.push_back(neighbor);
              open_list.push(make_tuple(priority, newCost, neighbor, newPath));
              cameFrom[neighbor] = current;
          }
      }
  }

  return {}; // Path not found
}

std::pair<std::vector<std::string>, int> a_star_search(const Graph& graph, const std::string& start, const std::string& goal, const std::map<std::string, int>& heuristic) {
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

void printPath(const vector<std::string>& path)  
{
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) { // Check if it's not the last city
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

// Function to convert a valid string from the user to Titlecase format
std::string titleCase(const std::string& str) {
    if (str.empty()) return "";
    std::string result = str;
    result[0] = std::toupper(result[0]);
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

// Function to get a valid string from the user that matches one of the strings in vectorStrings
std::string getValidString(const std::string& prompt, const std::vector<std::string>& vectorStrings) {
  std::string myString;
  bool found = false;
  do {
    std::cout << prompt;
    std::getline(std::cin, myString);
    if (myString.empty()) {
      continue; // Prompt again if the input is empty
    }
    myString = titleCase(myString); // Convert user input to title case for comparison
    for (const auto& targetString : vectorStrings) {
      if (myString == titleCase(targetString)) { // Convert targetString to title case for a case-insensitive comparison
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "Input not valid. Please try again.\n";
    }
  } while (!found);
  return myString;
}


int main() {
  
  // E.g from "Timisoara" to "Bucharest"

  // Variables for Romania map (Uniform Cost Search and A* Search)
  std::string startCity, endCity;

  startCity = getValidString("Enter start city (e.g., Arad): ", CITIES);
  endCity = getValidString("Enter goal city (e.g., Bucharest): ", CITIES);

  // auto path = uniformCostSearch(romaniaMap, StatCity, EndCity);
  auto result = a_star_search(romaniaMap, startCity, endCity, heuristic);
  std::cout << "A* Search Path: ";
  auto path = result.first;
  auto cost = result.second;
  printPath(path);
  std::cout << "A* Search Path Cost: ";
  std::cout << cost;
  std::cout << "\n";

  return 0;
}
