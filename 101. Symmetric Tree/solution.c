/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool is_symmetric(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right != NULL) return false;
    if (left != NULL && right == NULL) return false;
    if (left == NULL && right == NULL) return true;
    if (left->val == right->val)
        return is_symmetric(left->left, right->right) &&
            is_symmetric(left->right, right->left);
    return false;
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return is_symmetric(root->left, root->right);
}