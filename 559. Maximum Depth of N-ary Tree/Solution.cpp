/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int max = 0, tmp;
        for (auto node : root->children) {
            tmp = maxDepth(node);
            if (tmp > max) max = tmp;
        }
        return max + 1;
    }
};
