class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            memset(children, 0, sizeof(children));
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* node = root;

            for (char c : word) {
                int idx = c - 'a';

                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }

                node = node->children[idx];
            }

            node->word = word;
        }

        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans) {
        char c = board[i][j];

        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear();
        }

        board[i][j] = '#';

        if (i > 0) dfs(board, i - 1, j, node, ans);
        if (j > 0) dfs(board, i, j - 1, node, ans);
        if (i < board.size() - 1) dfs(board, i + 1, j, node, ans);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, ans);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};