/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root(root), n(0) {
        vector<TreeNode*> level(1, root), tmp;
        while (!level.empty()) {
            this->n += level.size();
            tmp.clear();
            for (auto node : level) {
                if (node->left) tmp.push_back(node->left); else break;
                if (node->right) tmp.push_back(node->right); else break;
            }
            level = tmp;
        }
    }
    
    int insert(int v) {
        TreeNode *node = root;
        uint32_t i = 1, n = ++this->n;
        while (n >> i) ++i;
        if (i > 1) for (i -= 2; i > 0; --i)
            node = ((n >> i) & 1) ? node->right : node->left;
        ((n & 1) ? node->right : node->left) = new TreeNode(v);
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    TreeNode* root;
    uint32_t n;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */