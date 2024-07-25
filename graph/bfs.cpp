#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

/* 

Why use BFS and not DFS to discover the shortest path?
With DFS, we can only know if we can reach E from S, but we can't keep
track of the nodes it took to reach the end. We only can achive this by
using a BFS algorithm.

*/

void exploreNeighbors(
    vector<vector<char>>& grid,
    int m, int n,
    vector<vector<bool>>& visited,
    vector<vector<pair<int,int>>>& prev,
    queue<pair<int,int>>& qe
) {
    int dm[4] = {0, -1, 0, 1};
    int dn[4] = {-1, 0, 1, 0};

    pair<int, int> origin = make_pair(m,n);

    for (int i = 0; i < 4; i++) {
        int mm = m + dm[i];
        int nn = n + dn[i];
        if (mm < 0 || nn < 0) continue;
        if (mm >= grid.size() || nn >= grid[0].size()) continue;
        if (grid[mm][nn] == '#' || visited[mm][nn]) continue;
        visited[mm][nn] = true;
        pair<int, int> dest = make_pair(mm,nn);
        prev[mm][nn] = origin;
        qe.push(dest);
    }
}

vector<pair<int, int>> reconstructPath(pair<int,int> curr, vector<vector<pair<int,int>>>& prev, pair<int,int> start) {
    vector<pair<int, int>> path;
    path.push_back(curr);
    while (curr != start) {
        curr = prev[curr.first][curr.second];
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
}

int bfs(vector<vector<char>>& grid, int m, int n) {
    vector<vector<pair<int,int>>> prev(grid.size(), vector<pair<int,int>>(grid[0].size()));
    queue<pair<int,int>> qe;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    qe.push(make_pair(m, n));
    visited[m][n] = true;
    while (!qe.empty()) {
        pair<int,int> t = qe.front();
        qe.pop();
        if (grid[t.first][t.second] == 'E') {
            vector<pair<int, int>> path = reconstructPath(t, prev, make_pair(m, n));
            for (auto& i : path) {
                cout << i.first << ", " << i.second << endl;
            }
            return path.size();
        }
        exploreNeighbors(grid, t.first, t.second, visited, prev, qe);
    }
    return -1;
}

int main() {
    vector<vector<char>> grid = {
        {'S', '.', '.', '#', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '#', '.'},
        {'.', '#', '.', '.', '.', '.', '.'},
        {'.', '.', '#', '#', '.', '.', '.'},
        {'#', '.', '#', 'E', '.', '#', '.'},
    };
    
    cout << "Passos: " << bfs(grid, 0, 0) << endl;

    return 0;
}