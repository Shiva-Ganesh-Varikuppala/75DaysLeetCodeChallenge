class WordDictionary {
    struct TrieNode {
        TrieNode* child[26];
        bool end;

        TrieNode() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            end = false;
        }
    };

    TrieNode* root;

    bool dfs(const string& word, int idx, TrieNode* node) {
        if (!node) return false;

        if (idx == word.size())
            return node->end;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, idx + 1, node->child[i]))
                    return true;
            }
            return false;
        }

        return dfs(word, idx + 1, node->child[word[idx] - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!cur->child[i])
                cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */