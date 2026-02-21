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
    TreeNode* solve(vector<int>&preorder,int &i,int bound){
        if(i>=preorder.size() || preorder[i]>bound )
        return nullptr;
            TreeNode* node=new TreeNode(preorder[i++]);
            node->left=solve(preorder,i,node->val);
            node->right=solve(preorder,i,bound);
            return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode* root=new TreeNode(INT_MAX);
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};