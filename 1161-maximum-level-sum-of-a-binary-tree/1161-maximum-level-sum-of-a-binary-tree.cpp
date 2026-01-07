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
    int maxLevelSum(TreeNode* root) {
        int ans=0,maxSum=INT_MIN;
        queue<TreeNode*>q;
        int currSum=0;
        if(root==nullptr)
        return 0;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int s=q.size();
            level++;
            while(s--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
                currSum+=node->val;
            }
            // cout<<currSum<<endl;
            // cout<<maxSum<<endl;
            if(currSum>maxSum){
            ans=level;
            maxSum=currSum;
            }
            currSum=0;
        }
        return ans;
    }
};