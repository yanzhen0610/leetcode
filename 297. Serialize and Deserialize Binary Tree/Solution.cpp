/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        
        TreeNode* node;
        queue<TreeNode*> q;
        ostringstream b;
        
        b << '[' << root->val;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            
            b << ',';
            if (node)
            {
                q.push(node->left);
                q.push(node->right);
                b << node->val;
            }
            else b << "null";
        }
        
        b << ']';
        
        return b.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        
        int tmp;
        char null[5];
        TreeNode *root = nullptr, *node;
        queue<TreeNode*> q;
        istringstream s(data);
        
        s.get();
        s >> tmp;
        root = new TreeNode(tmp);
        q.push(root);
        
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            
            s.get(); // comma
            if (s.peek() == 'n') s.get(null, 5);
            else
            {
                s >> tmp;
                node->left = new TreeNode(tmp);
                q.push(node->left);
            }
            
            s.get(); // comma
            if (s.peek() == 'n') s.get(null, 5);
            else
            {
                s >> tmp;
                node->right = new TreeNode(tmp);
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));