/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void serialize(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += "$" + to_string(root->val) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }

    vector<int> buildLPS(string &pat) {
        int n = pat.size();
        vector<int> lps(n, 0);

        int len = 0, i = 1;
        while (i < n) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }

    bool KMP(string &txt, string &pat) {
        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == pat.size()) return true;
            else if (i < txt.size() && txt[i] != pat[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "", s2 = "";

        serialize(root, s1);
        serialize(subRoot, s2);

        return KMP(s1, s2);
    }
};