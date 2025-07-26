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
    int f(TreeNode* node){
        if(node==nullptr)
        return 0;
        int l=f(node->left);
        if(l==-1)
        return -1;
        int r=f(node->right);
        if(r==-1)
        return -1;
       if(abs(r-l)>1)
       return -1;
       return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        return true;
        if(f(root)==-1)
        return false;
        return true;
        
    }
};