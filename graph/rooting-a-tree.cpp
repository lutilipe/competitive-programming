#include <iostream>
#include <vector>
#include <unordered_map>

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

TreeNode* treeFromGraph(unordered_map<int, vector<int>>& graph, TreeNode* node, TreeNode* parent) {
    if (graph.find(node->val) == graph.end()) return nullptr;
    for (const auto& child : graph[node->val]) {
        if (parent != nullptr && child == parent->val) continue;
        TreeNode* childNode = new TreeNode(child, node, {});
        node->children.push_back(childNode);
        treeFromGraph(graph, childNode, node);
    }
    return node;
}

void printTree(TreeNode* node, int depth) {
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << node->val << endl;
    for (TreeNode* child : node->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    vector<vector<int>> graph = {{0,1},{0,2},{0,5},{2,3},{5,4},{5,6}};

    unordered_map<int, vector<int>> adjacencyList;

    for (const auto& edge : graph) {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }

    TreeNode* root = treeFromGraph(
        adjacencyList,
        new TreeNode(graph[0][0], nullptr, {}),
        nullptr
    );

    printTree(root, 0);
    
    return 0;
}