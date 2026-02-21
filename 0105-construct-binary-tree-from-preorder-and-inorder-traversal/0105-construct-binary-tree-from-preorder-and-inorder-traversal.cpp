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
        if(is>ie || ps>pe)
        return nullptr;
        TreeNode* node=new TreeNode(preorder[ps]);
        int ir=mp[preorder[ps]];
        int x=ir-is;
        node->left=buildTree(preorder,ps+1,ps+x,inorder,is,ir-1,mp);
        node->right=buildTree(preorder,ps+x+1,pe,inorder,ir+1,ie,mp);
        return node;
    }
};