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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,int ps,int pe, vector<int>& inorder,int is,int ie,map<int,int>&mp){
       if (is > ie || ps > pe)
    return nullptr;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inroot=mp[root->val];
        int numsleft=inroot-is;
        root->left=buildTree(preorder,ps+1,ps+numsleft,inorder,is,inroot-1,mp);
        root->right=buildTree(preorder,ps+numsleft+1,pe,inorder,inroot+1,ie,mp);
        return root;
    }
};