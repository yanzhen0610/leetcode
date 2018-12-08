class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // shared_ptr<TrieNode> node = root;
        TrieNode* node = &root;
        for (auto c : word)
        {
            c -= 'a';
            if (!node->children[c])
                // node->children[c] = make_shared<TrieNode>();
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // shared_ptr<TrieNode> node = root;
        TrieNode* node = &root;
        for (auto c : word)
        {
            c -= 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // shared_ptr<TrieNode> node = root;
        TrieNode* node = &root;
        for (auto c : prefix)
        {
            c -= 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return true;
    }
private:
    struct TrieNode
    {
        // unordered_map<char, shared_ptr<TrieNode>> children{26};
        TrieNode *children[26]{};
        bool end = false;
    // };
    } root;
    // shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */