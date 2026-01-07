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
long long  ans=0;
long long  mod=1000000007;
    long long  func(TreeNode* node,long long total){
         long long left=0,right=0;
         if(node->left!=nullptr)
         left=func(node->left,total);
         if(node->right!=nullptr)
         right=func(node->right,total);
         
         long long  current=(left+right+node->val);
         ans=max(ans,current*(total-current));
         return current;
    }
    int maxProduct(TreeNode* root) {
        long long total=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            total+=node->val;
            if(node->left!=nullptr)
            q.push(node->left);
            if(node->right!=nullptr)
            q.push(node->right);
        }
        func(root,total);
        return ans%mod;
    }
};