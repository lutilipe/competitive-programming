#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>

using namespace std;

int dfs(
    int i,
    int node,
    vector<char>& sortedNodes,
    unordered_map<char, bool>& V,
    unordered_map<char, vector<pair<char,int>>>& graph
) {
    V[node] = true;
    for (auto& childNode : graph[node]) {
        if (!V[childNode.first]) {
            i = dfs(i, childNode.first, sortedNodes, V, graph);
        }
    }
    sortedNodes[i] = node;
    return i - 1;
}

void topoSort(
    int n, 
    unordered_set<char>& nodes, 
    vector<char>& sortedNodes, 
    unordered_map<char, vector<pair<char,int>>>& graph
) {
    unordered_map<char, bool> V;
    for (int node : nodes) {
        V[node] = false;
    }

    int i = n-1;

    for (auto& it : graph) {
        if (!V[it.first]) {
            i = dfs(i, it.first, sortedNodes, V, graph);
        }
    }
}

int main() {
    // C => M
    vector<vector<char>> graph = {
        {'A','B', 3},
        {'A','C', 6},
        {'B','C', 4},
        {'B','D', 4},
        {'C','D', 8},
        {'B','E', 11},
        {'D','E', -4},
        {'D','F', 5},
        {'C','G', 11},
        {'D','G', 2},
        {'E','H', 9},
        {'F','H', 1},
        {'G','H', 2},
    };

    unordered_map<char, vector<pair<char,int>>> adjacencyList;
    unordered_set<char> nodes;


    for (auto& node : graph) {
        adjacencyList[node[0]].push_back(make_pair(node[1], node[2]));
        nodes.insert(node[0]);
        nodes.insert(node[1]);
    }

    int n = nodes.size();

    vector<char> sortedNodes(n, 0);

    topoSort(n, nodes, sortedNodes, adjacencyList);

    unordered_map<char, int> dist;
    for (auto& i : sortedNodes) {
        dist[i] = INT_MAX;
    }
    dist[sortedNodes[0]] = 0;
    for (int i = 0; i < n; i++) {
        int node = sortedNodes[i];
        if (dist[node] != INT_MAX) {
            vector<pair<char,int>> edges = adjacencyList[node];
            if (edges.size()) {
                for (auto& it : edges) {
                    int newDist = dist[node] + it.second;
                    dist[it.first] = min(newDist, dist[it.first]);
                }
            }
        }
    }

    cout << dist[sortedNodes[n-1]] << endl;

    return 0;
}