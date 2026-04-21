/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int sz = q.size();
            ans.emplace_back();
            ans.back().reserve(sz);

            while (sz--) {
                TreeNode* node = q.front();
                q.pop_front();

                ans.back().push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }

        return ans;
    }
};