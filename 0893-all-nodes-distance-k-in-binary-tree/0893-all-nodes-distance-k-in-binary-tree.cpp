/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void solve(int x,int d,unordered_map<int,vector<int>>&adj,int
    // k,unordered_map<int,bool>&vis){
    //    if(vis[x])
    //    return;
    //    vis[x]=true;
    //    if(d==k)
    //    {
    //     ans.push_back(x);
    //     return;
    //    }
    //    for(int i:adj[x]){
    //     solve(i,d+1,adj,k,vis);
    //    }
    // }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        vector<int> ans;
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
        q1.push({target->val, 0});
        vis.insert(target->val);

        while (!q1.empty()) {
            int node = q1.front().first;
            int d = q1.front().second;
            q1.pop();
            if (d == k) {
                ans.push_back(node);
                continue;
            }
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