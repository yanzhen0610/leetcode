/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recursion(result, root);
        return result;
    }
    static void recursion(vector<int>& result, TreeNode* node)
    {
        if (node == nullptr) return;
        result.push_back(node->val);
        recursion(result, node->left);
        recursion(result, node->right);
    }
};