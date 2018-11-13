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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        auto it = nums.cbegin();
        stk.push_back(nums.empty() ? nullptr : new TreeNode(*it));
        while (++it != nums.cend())
        {
            TreeNode *new_node = new TreeNode(*it), *node = nullptr;
            while (!stk.empty() && stk.back()->val < *it)
            {
                node = stk.back();
                stk.pop_back();
            }
            new_node->left = node;
            if (!stk.empty())
                stk.back()->right = new_node;
            stk.push_back(new_node);
        }
        return stk.front();
    }
};