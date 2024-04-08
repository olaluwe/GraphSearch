#ifndef DFSBFS_H
#define DFSBFS_H

#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class DfsBfs {
public:
    static std::vector<char> bfs(std::map<char, std::vector<char>>& graph, char start, char goal);
    static std::vector<char> dfs(char start, char goal, const std::map<char, std::vector<char>>& graph);

private:
    static bool dfsUtil(char node, char goal, std::map<char, bool>& visited, std::vector<char>& path, const std::map<char, std::vector<char>>& graph);
};

#endif // DFSBFS_H
