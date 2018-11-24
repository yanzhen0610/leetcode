/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool has_path_sum(struct TreeNode* node, int sum, int accumulated)
{
    if (node == NULL) return false;
    accumulated += node->val;
    if (node->left == NULL && node->right == NULL && accumulated == sum) return true;
    return has_path_sum(node->left, sum, accumulated) || has_path_sum(node->right, sum, accumulated);
}
bool hasPathSum(struct TreeNode* root, int sum) {
    return has_path_sum(root, sum, 0);
}