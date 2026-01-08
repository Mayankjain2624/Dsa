/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* node,long long l,long long r){
        if(node==nullptr)
        return true;
        if(l>=node->val || node->val>=r)
        return false;
        bool lc=solve(node->left,l,node->val);
        bool rc=solve(node->right,node->val,r);
        return lc&&rc;

    }
    bool isValidBST(TreeNode* root) {

        return solve(root,LLONG_MIN,LLONG_MAX);
         
    }
};