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
// void postorder(TreeNode* node,vector<int>&ans){
//     if(node==nullptr)
//     return;
//     postorder(node->left,ans);
//     postorder(node->right,ans);
//     ans.push_back(node->val);
// }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        // postorder(root,ans);
        // return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        if(root==nullptr)
        return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            if(node->left!=nullptr)
              st1.push(node->left);
              if(node->right!=nullptr)
              st1.push(node->right);
              st2.push(node);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};