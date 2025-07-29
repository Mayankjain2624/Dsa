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
vector<int>ans;
    void solve(int x,int d,vector<vector<int>>&adj,int k,vector<bool>&vis){
       if(vis[x])
       return;
       vis[x]=true;
       if(d==k)
       {
        ans.push_back(x);
        return;
       }
       for(int i:adj[x]){
        solve(i,d+1,adj,k,vis);
       }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>>adj(500);
        queue<TreeNode*>q;
        if(root!=nullptr)
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=nullptr)
            {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            q.push(node->left);
            }
            if(node->right!=nullptr)
            {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            q.push(node->right);
            }
        }
        vector<bool>vis(500,false);
       solve(target->val,0,adj,k,vis);
       return ans;
    }
};