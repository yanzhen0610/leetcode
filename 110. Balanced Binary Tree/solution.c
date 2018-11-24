/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int recursion(struct TreeNode* node)
{
    if (node == NULL) return 0;
    int l = recursion(node->left);
    if (l == -1) return -1;
    int r = recursion(node->right);
    if (r == -1) return -1;
    if (abs(l - r) >= 2) return -1;
    return ((l > r) ? l : r) + 1;
}
bool isBalanced(struct TreeNode* root) {
    return recursion(root) != -1;
}