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
    int righth(TreeNode* node){
        int h=0;
        while(node!=nullptr)
        {
            h++;
            node=node->left;
        }
        return h;
    }
    int lefth(TreeNode* node){
        int h=0;
        while(node!=nullptr)
        {
            h++;
            node=node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        if(root==nullptr)
        return 0;
        int lh=lefth(root->left);
        int rh=righth(root->right);
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};