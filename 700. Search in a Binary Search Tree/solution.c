/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root)
    {
        if (root->val == val) return root;
        if (root->val < val) root = root->right;
        else root = root->left;
    }
    return root;
}