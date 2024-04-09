#include <UniformCost.h>

// Helper function to reconstruct the path from start to goal
vector<string> reconstructPath(const map<string, string>& cameFrom, const string& goal) {
    vector<string> path;
    string current = goal;
    while (current != "") {
        path.push_back(current);
        current = cameFrom.at(current);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Uniform Cost Search function
pair<vector<string>, int> UniformCost::UniformCostSearch(const Graph& graph, const string& start, const string& goal) 
{
    // Min heap to prioritize nodes with lower cost
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> frontier;
    frontier.emplace(0, start);

    map<string, int> costSoFar; // Tracks the cost to reach each node
    costSoFar[start] = 0;

    map<string, string> cameFrom; // Tracks the best path to each node
    cameFrom[start] = ""; // Start node has no predecessor

    while (!frontier.empty()) {
        auto current = frontier.top();
        frontier.pop();

        string currentNode = current.second;
        int currentCost = current.first;

        // Goal check
        if (currentNode == goal) {
            return {reconstructPath(cameFrom, goal), currentCost};
        }

        for (const auto& next : graph.at(currentNode)) {
            string nextNode = next.first;
            int newCost = currentCost + next.second;
            if (!costSoFar.count(nextNode) || newCost < costSoFar[nextNode]) {
                costSoFar[nextNode] = newCost;
                frontier.emplace(newCost, nextNode);
                cameFrom[nextNode] = currentNode;
            }
        }
    }

    // If the goal was not reached
    return {vector<string>(), -1};
}