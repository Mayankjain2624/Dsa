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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> ds;
        queue<tuple<TreeNode*, int, int>> q;
        q.emplace(root, 0, 0);

        while (!q.empty()) {
            auto [node, x, y] = q.front();
            q.pop();
            ds[y][x].emplace(node->val);

            if (node->left)
                q.emplace(node->left, x + 1, y - 1);
            if (node->right)
                q.emplace(node->right, x + 1, y + 1);
        }

        vector<vector<int>> ans;
        for (auto& [y, mp] : ds) {
            vector<int> col;
            for (auto& [x, nodes] : mp) {
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
