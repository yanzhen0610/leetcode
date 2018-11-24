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
    if (deeper_begin == NULL) deeper_begin = root->right;
    while (deeper_begin)
    {
        deeper = begin;
        while (shallower)
        {
            if (shallower->left) deeper = deeper->next = shallower->left;
            if (shallower->right) deeper = deeper->next = shallower->right;
            shallower = shallower->next;
        }
        shallower = deeper_begin;
        while (deeper_begin)
        {
            if (deeper_begin->left)
            {
                deeper_begin = deeper_begin->left;
                break;
            }
            if (deeper_begin->right)
            {
                deeper_begin = deeper_begin->right;
                break;
            }
            deeper_begin = deeper_begin->next;
        }
    }
    free(begin);
}