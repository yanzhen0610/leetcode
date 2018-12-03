/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root)
        {
            stack.push_back(root);
            while (root->left) stack.push_back(root = root->left);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto p = stack.back();
        auto t = p->val;
        stack.pop_back();
        if (p->right)
        {
            stack.push_back(p = p->right);
            while (p->left) stack.push_back(p = p->left);
        }
        return t;
    }
private:
    vector<const TreeNode*> stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */