/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool validate(struct TreeNode* node, int64_t lb, int64_t rb)
{
    if (node == NULL) return true;
    if (node->val <= lb || node->val >= rb) return false;
    return validate(node->left, lb, node->val) && validate(node->right, node->val, rb);
}
bool isValidBST(struct TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}