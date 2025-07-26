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
   bool ans=true;
    int f(TreeNode* node){
        int l=0,r=0;
        if(node->left!=nullptr)
        l=1+f(node->left);
        if(node->right!=nullptr)
        r=1+f(node->right);
       if(abs(r-l)>1)
       ans=false;
       return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        return true;
        f(root);
        return ans;
    }
};