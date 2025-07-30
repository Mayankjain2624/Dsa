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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
        TreeNode* root=buildTree(inorder,0,n-1,postorder,0,n-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int,int>&mp){
        if (is > ie || ps > pe)
    return nullptr;
         TreeNode* root = new TreeNode(postorder[pe]);
         int iroot=mp[root->val];
         int numsleft=iroot-is;
         root->left=buildTree(inorder,is,iroot-1,postorder,ps,ps+numsleft-1,mp);
         root->right=buildTree(inorder,iroot+1,ie,postorder,ps+numsleft,pe-1,mp);
         return root;
    }
};