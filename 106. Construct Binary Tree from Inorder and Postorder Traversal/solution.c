/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* new_node(int value, struct TreeNode* left, struct TreeNode* right)
{
    struct TreeNode* new = malloc(sizeof(struct TreeNode));
    new->val = value;
    new->left = left;
    new->right = right;
    return new;
}
int* linear_search(int* a, int l, int t)
{
    for (int i = 0; i < l; ++i)
        if (a[i] == t) return a + i;
    return NULL;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize <= 0 || postorderSize <= 0) return NULL;

    int root_value = postorder[postorderSize - 1];
    int* root_inorder = linear_search(inorder, inorderSize, root_value);
    int left_len = root_inorder - inorder;
    int right_len = inorderSize - left_len - 1;

    struct TreeNode* left_subtree = buildTree(inorder, left_len, postorder, left_len);
    struct TreeNode* right_subtree = buildTree(root_inorder + 1, right_len, postorder + left_len, right_len);
    
    return new_node(root_value, left_subtree, right_subtree);
}