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
    // void preorder(TreeNode* node,vector<int>&ans){
    //     if(node==nullptr)
    //     return;
    //     ans.push_back(node->val);
    //     preorder(node->left,ans);
    //     preorder(node->right,ans);

    // }
    vector<int> preorderTraversal(TreeNode* root) {
          vector<int>ans;
        //   preorder(root,ans);
        //   return ans;
        if(root==nullptr)
        return ans;
        stack<TreeNode* >st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr)
            st.push(node->right);
            if(node->left!=nullptr)
            st.push(node->left);
        }
        return ans;
    }
};