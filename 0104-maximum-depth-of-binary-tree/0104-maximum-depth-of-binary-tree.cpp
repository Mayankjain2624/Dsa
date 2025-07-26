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
    int depth(TreeNode* node){
        int l=0,r=0;
        if(node->left!=nullptr)
         l=1+depth(node->left);
        if(node->right!=nullptr)
         r=1+depth(node->right);
        return max(l,r);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
        return 0;
        return depth(root)+1;
        
    }
};