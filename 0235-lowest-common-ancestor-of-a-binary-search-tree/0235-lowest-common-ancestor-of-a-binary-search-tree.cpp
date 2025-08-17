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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==p || root==q)
        return root;
        TreeNode* llca=nullptr;
        TreeNode* rlca=nullptr;
        if(p->val<root->val && q->val<root->val)
        llca=lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)
        rlca=lowestCommonAncestor(root->right,p,q);
        else
        {
            llca=lowestCommonAncestor(root->left,p,q);
            rlca=lowestCommonAncestor(root->right,p,q);
        }
        if(llca==nullptr)
        return rlca;
        if(rlca==nullptr)
        return llca;
        else{
            return root;
        }
    }
};