#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TreeNode {
    public:
        int val;
        vector<TreeNode*> children;
        TreeNode* parent;
        TreeNode(int v): val(v) {};
        TreeNode(int v, TreeNode* p): val(v), parent(p) {};
        TreeNode(int v, TreeNode* p, vector<TreeNode*> c): val(v), parent(p), children(c) {};
};

unordered_map<int, vector<int>> createAdjacencyList(vector<vector<int>>& tree) {
    unordered_map<int, vector<int>> adjacencyList;

    for (int i = 0; i < tree.size(); i++) {
        adjacencyList[tree[i][0]].push_back(tree[i][1]);
        adjacencyList[tree[i][1]].push_back(tree[i][0]);
    }

    return adjacencyList;
}

int findTreeCenter(unordered_map<int, vector<int>>& adjacencyList) {
    unordered_map<int,int> degrees;
    queue<int> leafNodes;

    for (auto& it : adjacencyList) {
        degrees[it.first] = it.second.size();
        if (degrees[it.first] == 1) {
            leafNodes.push(it.first);
        }
    }

    int count = adjacencyList.size();
    while (count > 2) {
        int nodesVisited = leafNodes.size();
        count -= nodesVisited;
        for (int i = 0; i < nodesVisited; i++) {
            int leaf = leafNodes.front();
            leafNodes.pop();
            degrees[leaf]--;

            for (int neighbor : adjacencyList[leaf]) {
                if (--degrees[neighbor] == 1) {
                    leafNodes.push(neighbor);
                }
            }
        }
    }

    vector<int> centers;

    while (!leafNodes.empty()) {
        centers.push_back(leafNodes.front());
        leafNodes.pop();
    }

    return centers[0];
}

void constructTree(unordered_map<int, vector<int>>& adjacencyList, TreeNode* root, TreeNode* parent) {
    if (!root) return;
    vector<int> children = adjacencyList[root->val];
    for (auto child : children) {
        if (parent && child == parent->val) continue;
        TreeNode* childNode = new TreeNode(child);
        root->children.push_back(childNode);
        constructTree(adjacencyList, childNode, root); 
    }
}

string encode(TreeNode* root) {
    if (!root) return "";
    if (root->children.size() == 1) {
        return "()";
    }
    vector<string> currNodes;
    for (auto child : root->children) {
        currNodes.push_back(encode(child));
    }
    sort(currNodes.begin(), currNodes.end(), [&](string& s1, string& s2) {
        return s1.size() > s2.size();
    });
    string ans = "(";
    for (auto n : currNodes) {
        ans+=n;
    }
    ans+= ')';
    return ans;
}

bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
    return encode(root1) == encode(root2);
}

int main() {
    vector<vector<int>> tree1 = {{0,1},{1,2},{1,4},{4,3},{3,5}};
    vector<vector<int>> tree2 = {{0,1},{1,2},{2,4},{4,3},{4,5}};

    unordered_map<int, vector<int>> adjacencyList1 = createAdjacencyList(tree1);
    unordered_map<int, vector<int>> adjacencyList2 = createAdjacencyList(tree2);

    int center1 = findTreeCenter(adjacencyList1);
    int center2 = findTreeCenter(adjacencyList2);

    TreeNode* root1 = new TreeNode(center1, nullptr, {});
    TreeNode* root2 = new TreeNode(center2, nullptr, {});

    constructTree(adjacencyList1, root1, nullptr);
    constructTree(adjacencyList2, root2, nullptr);

    cout << isIsomorphic(root1, root2) << endl;

    return 0;
}