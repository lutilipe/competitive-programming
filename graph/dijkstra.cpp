#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits.h>

using namespace std;

class PQComparator {
    public:
    bool operator() (pair<int, int> p1, pair<int, int>p2) { return p1.second > p2.second; }
};


int dijkstra(
    int start,
    int dest,
    unordered_set<int>& nodes,
    unordered_map<int, vector<pair<int, int>>>& adjacencyList
) {
    unordered_map<int, int> dist;

    for (auto& it : nodes) {
        dist[it] = INT_MAX;
    }

    unordered_map<int, bool> visited;
    for (auto& it : nodes) {
        visited[it] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, PQComparator> pq;

    dist[start] = 0;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();

        int from = node.first;
        int minValue = node.second;
        visited[from] = true;

        if (dist[from] < minValue) continue;

        vector<pair<int, int>> edges = adjacencyList[from];
        for (auto& edge : edges) {
            int to = edge.first;
            if (visited[to]) {
                continue;
            }
            int newDist = dist[from] + edge.second;
            if (newDist < dist[to]) {
                dist[to] = newDist;
                pq.push(make_pair(to, newDist));
            }
        }
    }

    return dist[dest] == INT_MAX ? -1 : dist[dest];
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {2, 3, 5},
        {1, 3, 1},
        {3, 4, 3},
    };

    unordered_map<int, vector<pair<int, int>>> adjacencyList;
    unordered_set<int> nodes;

    for (auto& edge : graph) {
        adjacencyList[edge[0]].push_back(make_pair(edge[1], edge[2]));
        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
    }

    int start = 0;
    int dest = 4;

    int dist = dijkstra(start, dest, nodes, adjacencyList);
    cout << dist << endl;

    return 0;
}