#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dfs(int i, char node, unordered_map<char,bool>& V, vector<char>& ans, unordered_map<char, vector<char>>& graph) {
    V[node] = true;
    for (auto& childNode : graph[node]) {
        if (!V[childNode]) {
            i = dfs(i, childNode, V, ans, graph);
        }
    }
    ans[i] = node;
    return i-1;
}

int main() {
    vector<vector<char>> graph = {
        {'C','B'},
        {'C','A'},
        {'B','D'},
        {'A','D'},
        {'E','A'},
        {'E','D'},
        {'D','G'},
        {'D','H'},
        {'H','J'},
        {'H','I'},
        {'E','F'},
        {'F','K'},
        {'F','J'},
        {'K','J'},
        {'G','I'},
        {'I','L'},
        {'J','M'},
        {'J','L'}
    };

    unordered_map<char, vector<char>> adjacencyList;
    unordered_set<char> nodes;

    unordered_map<char,bool> V;

    for (const auto& edge : graph) {
        adjacencyList[edge[0]].push_back(edge[1]);
        V[edge[0]] = false;
        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
    }

    int n = nodes.size();
    vector<char> ans(n, 0);

    int i = n-1;

    for (auto& it : adjacencyList) {
        if (!V[it.first]) {
            i = dfs(i, it.first, V, ans, adjacencyList);
        }
    }

    for (auto& i : ans) {
        cout << i << ", ";
    }
    cout << endl;
    
    return 0;
}