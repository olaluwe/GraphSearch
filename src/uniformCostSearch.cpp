#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <limits>
#include <algorithm>
#include <utility>
#include <cctype>

using namespace std;

typedef pair<int, string> WeightedEdge; // (weight, node)
typedef vector<WeightedEdge> AdjList;
typedef map<string, AdjList> Graph;

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
    {"Arad", {{75, "Zerind"}, {140, "Sibiu"}, {118, "Timisoara"}}},
    {"Zerind", {{75, "Arad"}, {71, "Oradea"}}},
    {"Oradea", {{71, "Zerind"}, {151, "Sibiu"}}},
    {"Sibiu", {{140, "Arad"}, {151, "Oradea"}, {99, "Fagaras"}, {80, "Rimnicu Vilcea"}}},
    {"Rimnicu Vilcea", {{80, "Sibiu"}, {97, "Pitesti"}, {146, "Crainova"}}},
    {"Crainova", {{146, "Rimnicu Vilcea"}, {138, "Pitesti"}, {120, "Drobeta"}}},
    {"Drobeta", {{120, "Crainova"}, {75, "Mehadia"}}},
    {"Mehadia", {{75, "Drobeta"}, {70, "Lugoj"}}},
    {"Lugoj", {{70, "Mehadia"}, {111, "Timisoara"}}},
    {"Timisoara", {{118, "Arad"}, {111, "Lugoj"}}},
    {"Fagaras", {{99, "Sibiu"}, {211, "Bucharest"}}},
    {"Pitesti", {{138, "Crainova"}, {97, "Rimnicu Vilcea"}, {101, "Bucharest"}}},
    {"Bucharest", {{101, "Pitesti"}, {211, "Fagaras"}, {85, "Urziceni"}, {90, "Giurgiu"}}},
    {"Giurgiu", {{90, "Bucharest"}}},
    {"Urziceni", {{85, "Bucharest"}, {142, "Vaslui"}, {98, "Hirsova"}}},
    {"Hirsova", {{98, "Urziceni"}, {86, "Eforie"}}},
    {"Eforie", {{86, "Hirsova"}}},
    {"Vaslui", {{142, "Urziceni"}, {92, "Iasi"}}},
    {"Iasi", {{92, "Vaslui"}, {87, "Neamt"}}},
    {"Neamt", {{87, "Iasi"}}}
};

vector<string> uniformCostSearchWithoutCost(const Graph& graph, const string& start, const string& goal) {
    priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> frontier;
    map<string, int> costSoFar;
    map<string, string> cameFrom;

    frontier.push(make_pair(0, start));
    costSoFar[start] = 0;
    cameFrom[start] = "";

    while (!frontier.empty()) {
        string current = frontier.top().second;
        frontier.pop();

        if (current == goal) break;

        for (auto& next : graph.at(current)) {
            int newCost = costSoFar[current] + next.first;
            if (!costSoFar.count(next.second) || newCost < costSoFar[next.second]) {
                costSoFar[next.second] = newCost;
                frontier.push(make_pair(newCost, next.second));
                cameFrom[next.second] = current;
            }
        }
    }

    // Reconstruct path from start to goal
    vector<string> path;
    for (string at = goal; at != start; at = cameFrom[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

std::pair<std::vector<std::string>, int> uniformCostSearch(const Graph& graph, const std::string& start, const std::string& goal) {
    std::priority_queue<WeightedEdge, std::vector<WeightedEdge>, std::greater<WeightedEdge>> frontier;
    std::map<std::string, int> costSoFar;
    std::map<std::string, std::string> cameFrom;

    frontier.push(std::make_pair(0, start));
    costSoFar[start] = 0;
    cameFrom[start] = "";

    while (!frontier.empty()) {
        std::string current = frontier.top().second;
        frontier.pop();

        if (current == goal) break;

        for (auto& next : graph.at(current)) {
            int newCost = costSoFar[current] + next.first;
            if (!costSoFar.count(next.second) || newCost < costSoFar[next.second]) {
                costSoFar[next.second] = newCost;
                frontier.push(std::make_pair(newCost, next.second));
                cameFrom[next.second] = current;
            }
        }
    }

    // Reconstruct path from start to goal
    std::vector<std::string> path;
    for (std::string at = goal; at != start; at = cameFrom[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    // Return both path and the total cost to reach the goal
    // If goal is not reachable, this returns the path as empty and cost as 0
    return {path, costSoFar[goal]};
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

    // Variables for Romania map (Uniform Cost Search and A* Search)
    std::string startCity, endCity;

    startCity = getValidString("Enter start city (e.g., Arad): ", CITIES);
    endCity = getValidString("Enter goal city (e.g., Bucharest): ", CITIES);

    // auto path = uniformCostSearch(romaniaMap, StatCity, EndCity);
    auto result = uniformCostSearch(romaniaMap, startCity, endCity);
    std::cout << "Uniform Cost Search Path: ";
    auto path = result.first;
    auto cost = result.second;
    printPath(path);
    std::cout << "Uniform Cost Search Cost: ";
    std::cout << cost;
    std::cout << "\n";

    return 0;
}
