/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* node = root;
    while (node)
    {
        if (node->val < val)
        {
            if (node->right) node = node->right;
            else
            {
                node->right = malloc(sizeof(struct TreeNode));
                node->right->left = NULL;
                node->right->right = NULL;
                node->right->val = val;
                break;
            }
        }
        else
        {
            if (node->left) node = node->left;
            else
            {
                node->left = malloc(sizeof(struct TreeNode));
                node->left->left = NULL;
                node->left->right = NULL;
                node->left->val = val;
                break;
            }
        }
    }
    return root;
}