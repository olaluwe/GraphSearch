#include "../include/DfsBfs.h"


std::vector<char> DfsBfs::BFS(std::map<char, std::vector<char>>& graph, char start, char goal) {
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

bool DfsUtil(char node, char goal, std::map<char, bool>& visited, std::vector<char>& path, const std::map<char, std::vector<char>>& graph) {
    if (node == goal) {
        path.push_back(node);
        return true;
    }

    visited[node] = true;

    for (char neighbour : graph.at(node)) {
        if (!visited[neighbour]) {
            if (DfsUtil(neighbour, goal, visited, path, graph)) {
                path.push_back(node);
                return true;
            }
        }
    }
    return false;
}

std::vector<char> DfsBfs::DFS(char start, char goal, const std::map<char, std::vector<char>>& graph) {
    std::map<char, bool> visited;
    std::vector<char> path;

    if (DfsUtil(start, goal, visited, path, graph)) {
        std::reverse(path.begin(), path.end());
    }
    return path;
}