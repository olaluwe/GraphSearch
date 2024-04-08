#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

const std::vector<char> VALID_CHARS = {
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y'
};

map<char, vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {}},
    {'C', {'D', 'E'}},
    {'D', {}},
    {'E', {'F', 'I'}},
    {'F', {'G', 'H'}},
    {'G', {}},
    {'H', {}},
    {'I', {'J', 'K', 'L'}},
    {'J', {}},
    {'K', {}},
    {'L', {'M'}},
    {'M', {'N'}},
    {'N', {'O', 'P'}},
    {'O', {}},
    {'P', {'Q', 'S'}},
    {'Q', {'R'}},
    {'R', {}},
    {'S', {'T', 'U'}},
    {'T', {}},
    {'U', {'V'}},
    {'V', {'X', 'W'}},
    {'W', {}},
    {'X', {'Y'}},
    {'Y', {}}
};

std::vector<char> DfsBfs::bfs(std::map<char, std::vector<char>>& graph, char start, char goal) {
    std::map<char, bool> visited;
    std::queue<std::vector<char>> q;
    q.push({start});

    while (!q.empty()) {
        std::vector<char> path = q.front();
        q.pop();
        char node = path.back();

        if (visited[node]) continue;
        visited[node] = true;

        if (node == goal) return path;

        for (char neighbour : graph[node]) {
            if (!visited[neighbour]) {
                std::vector<char> new_path = path;
                new_path.push_back(neighbour);
                q.push(new_path);
            }
        }
    }
    return {};  // Return empty vector if goal is not reachable
}

bool DfsBfs::dfsUtil(char node, char goal, std::map<char, bool>& visited, std::vector<char>& path, const std::map<char, std::vector<char>>& graph) {
    if (node == goal) {
        path.push_back(node);
        return true;
    }

    visited[node] = true;

    for (char neighbour : graph.at(node)) {
        if (!visited[neighbour]) {
            if (dfsUtil(neighbour, goal, visited, path, graph)) {
                path.push_back(node);
                return true;
            }
        }
    }
    return false;
}

std::vector<char> DfsBfs::dfs(char start, char goal, const std::map<char, std::vector<char>>& graph) {
    std::map<char, bool> visited;
    std::vector<char> path;

    if (dfsUtil(start, goal, visited, path, graph)) {
        std::reverse(path.begin(), path.end());
    }
    return path;
}

void printPath(const vector<char>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) { // Check if it's not the last node
            std::cout << " -> ";
        }
    }
    std::cout << endl;
}

char getValidChar(const std::string& prompt, const std::vector<char>& targetChars) {
    std::string input;
    bool found = false;

    do {
        std::cout << prompt;
        std::getline(std::cin, input); // Read the whole line into input

        // Ensure input consists of exactly one character
        if (input.length() == 1) {
            char myChar = std::toupper(input[0]); // Convert to uppercase to simplify comparison
            
            if (!targetChars.empty() && myChar >= targetChars.front() && myChar <= targetChars.back()) {
                for (char targetChar : targetChars) {
                    if (myChar == std::toupper(targetChar)) {
                        found = true;
                        return myChar; // Return as soon as a valid character is found
                    }
                }
            }
        }

        std::cout << "Invalid input. Please try again.\n";
    } while (!found);

    return '\0'; // Return a default or error character if the loop exits without finding a match
}

int main() {
    char startNode, goalNode;
    
    // bfs search
    startNode = getValidChar("Enter start node (A-Y): ", VALID_CHARS);
    goalNode = getValidChar("Enter goal node (A-Y): ", VALID_CHARS);

    vector<char> bfsPath = bfs(startNode, goalNode);
    std::cout << "BFS Path: ";
    printPath(bfsPath);

    // dfs search
    vector<char> dfsPath = dfs(startNode, goalNode);
    std::cout << "DFS Path: ";
    printPath(dfsPath);

    return 0;
}