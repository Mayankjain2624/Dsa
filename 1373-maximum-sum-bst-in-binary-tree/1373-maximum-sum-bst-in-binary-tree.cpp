/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
   // vector<int>= {isbst,min,max,sum}
   int maxSum=0;
    vector<int> solve(TreeNode* root){
        if(root==nullptr){
            return {1,INT_MAX,INT_MIN,0};
        }
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        int currVal=root->val;
        if(left[0]==1 && right[0]==1)
        {
            if(left[2]< currVal && currVal<right[1])
            {
                int ns=currVal+left[3]+right[3];
                    maxSum=max(maxSum,ns);
                return {1,min({left[1],right[1],currVal}), max({currVal,right[2],left[2]}),ns};
            }
            else
            return {0,0,0,0};
        }
        else
        {
            return {0,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) 
    { 
        vector<int>ans=solve(root); 
        return maxSum;
    }
};