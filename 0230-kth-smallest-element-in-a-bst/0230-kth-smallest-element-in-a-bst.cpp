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
vector<int> inOrder(TreeNode* root,vector<int>&inorder){
    TreeNode* node=root;
      stack<TreeNode*>st;
      while(node!=nullptr || !st.empty())
      {
        while(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }
        node=st.top();

        inorder.push_back(node->val);
        st.pop();
        node=node->right;
      }
      return inorder;
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        inOrder(root,inorder);
        // for(int i:inorder){
        //      cout<<i<<" ";
        // }
        //  cout<<endl;
         return inorder[k-1];
    }
};