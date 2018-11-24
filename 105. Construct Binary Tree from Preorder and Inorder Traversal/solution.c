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
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (inorderSize <= 0 || preorderSize <= 0) return NULL;
    
    int root_value = preorder[0];
    int* root_inorder = linear_search(inorder, inorderSize, root_value);
    int left_len = root_inorder - inorder;
    int right_len = inorderSize - left_len - 1;
    
    struct TreeNode* left_subtree = buildTree(preorder + 1, left_len, inorder, left_len);
    struct TreeNode* right_subtree = buildTree(preorder + left_len + 1, right_len, root_inorder + 1, right_len);
    
    return new_node(root_value, left_subtree, right_subtree);
}