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
    int amountOfTime(TreeNode* root, int target) {
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        // vector<int> ans;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if (node->right != nullptr) {
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        unordered_set<int> vis;
        queue<pair<int, int>> q1;
        q1.push({target, 0});
        vis.insert(target);
        int ans=0;
        while (!q1.empty()) {
            int node = q1.front().first;
            int d = q1.front().second;
            q1.pop();
            // if (d == k) {
            //     ans.push_back(node);
            //     continue;
            // }
            ans=max(ans,d);
            for (int i : adj[node]) {
                if (!vis.count(i)) {
                    vis.insert(i);
                    q1.push({i, d + 1});
                }
            }
        }

        return ans;
    }
};