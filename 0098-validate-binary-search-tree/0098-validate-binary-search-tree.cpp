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
bool inOrder(TreeNode* root){
    TreeNode* node=root;
      stack<TreeNode*>st;
      bool hasprev=false;
      int prev=-1;
      while(node!=nullptr || !st.empty())
      {
        while(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }
        node=st.top();
        if(hasprev && node->val<=prev)
        return false;
        hasprev=true;
        prev=node->val;
        st.pop();
        node=node->right;
      }
      return true;
}
    bool isValidBST(TreeNode* root) {

        return inOrder(root);
         
    }
};