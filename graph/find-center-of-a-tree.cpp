#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getCenterOfTree(unordered_map<int, vector<int>>& adjacencyList, int n) {
    unordered_map<int, int> degrees;

    vector<int> leaves;

    for (const auto& it : adjacencyList) {
        degrees[it.first] = it.second.size();
        if (degrees[it.first] == 1 || degrees[it.first] == 0) {
            degrees[it.first] = 0;
            leaves.push_back(it.first);
        } 
    }

    int count = leaves.size();
    while (count < n + 1) {
        vector<int> newLeaves;
        for (auto leaf : leaves) {
            for (const auto& neighbor : adjacencyList[leaf]) {
                degrees[neighbor] -= 1;
                if (degrees[neighbor] == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            degrees[leaf] = 0;

        }
        count += newLeaves.size();
        leaves = newLeaves;
    }
    return leaves;
}

int main() {
    vector<vector<int>> tree = {{0,1},{1,2},{2,9},{2,3},{2,6},{6,7},{6,8},{3,4},{3,5}};

    unordered_map<int, vector<int>> adjacencyList;

    for (const auto& edge : tree) {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }

    vector<int> centers = getCenterOfTree(adjacencyList, tree.size());

    for (auto& center : centers) {
        cout << center << endl;
    }

    return 0;
}