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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* og=root;
        if(root==nullptr)
        return root;
        if(root->val==key)
        {
            TreeNode* rc=root;
            // delete rc;
            return helper(root);
        }
        while(root!=nullptr){
            if(root->val<key){
                if(root->right!=nullptr && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                root=root->right;
            }
            else 
            {
                 if(root->left!=nullptr && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                 }
                 root=root->left;
            }
        }
        return og;
    }
    TreeNode* helper(TreeNode* root) {
         if(root->left==nullptr && root->right==nullptr)
         return nullptr;
         if(root->left==nullptr)
         return root->right;
         if(root->right==nullptr)
         return root->left;
         TreeNode* leftchild=root->left;
         TreeNode* rml=root->left;
         while(rml->right!=nullptr){
            rml=rml->right;
         }
         rml->right=root->right;
         delete root;
         return leftchild;
    }
};