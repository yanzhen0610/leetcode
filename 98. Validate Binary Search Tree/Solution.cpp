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
    bool isValidBST(const TreeNode* root) {
        vector<const TreeNode*> stack;
        const TreeNode* prev = NULL;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if (prev && root->val <= prev->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};