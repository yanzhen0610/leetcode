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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        level_order(result, root, 0);
        return result;
    }
    static void level_order(vector<vector<int>>& result, TreeNode* node, int level)
    {
        if (node == nullptr) return;
        if (result.size() <= level) result.emplace_back(vector<int>());
        result[level].push_back(node->val);
        level_order(result, node->left, level + 1);
        level_order(result, node->right, level + 1);
    }
};