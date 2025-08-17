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
   void inOrder(TreeNode* root,vector<int>&inorder){
    stack<TreeNode*>st;
    TreeNode* node=root;
    while(node!=nullptr ||  !st.empty()){
        while(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }
        node=st.top();
        st.pop();
        inorder.push_back(node->val);
        node=node->right;
    }
   }
    bool isValidBST(TreeNode* root) {
        vector<int>inorder,ic;
        inOrder(root,inorder);
         ic=inorder;
         sort(ic.begin(),ic.end());
         if(ic[0]!=inorder[0])
         return false;
         for(int i=1;i<inorder.size();i++){
            if(ic[i]!=inorder[i] || ic[i]==ic[i-1])
            return false;
         }
         return true;
    }
};