/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (root == NULL) return;
    struct TreeLinkNode* begin = malloc(sizeof(struct TreeLinkNode));
    struct TreeLinkNode *shallower = root, *deeper, *deeper_begin = root->left;
    while (deeper_begin)
    {
        deeper = begin;
        while (shallower)
        {
            deeper = deeper->next = shallower->left;
            deeper = deeper->next = shallower->right;
            shallower = shallower->next;
        }
        shallower = deeper_begin;
        deeper_begin = deeper_begin->left;
    }
    free(begin);
}