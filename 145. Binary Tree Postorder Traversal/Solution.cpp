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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(result, root);
        return result;
    }
    static void postorder(vector<int>& result, TreeNode* node)
    {
        if (node == nullptr) return;
        postorder(result, node->left);
        postorder(result, node->right);
        result.push_back(node->val);
    }
};