/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   vector<TreeNode*>pv,qv;
  void solve(TreeNode* node, TreeNode* p, TreeNode* q,vector<TreeNode*>&temp){
      if(node==nullptr)
      return;
      temp.push_back(node);
      if(node==p)
      pv=temp;
      if(node==q)
      qv=temp;
      solve(node->left,p,q,temp);
      solve(node->right,p,q,temp);
      temp.pop_back();
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*>temp;
       solve(root,p,q,temp);
        for(int i=pv.size()-1;i>=0;i--){
            for(int j=qv.size()-1;j>=0;j--){
                if(pv[i]==qv[j])
                return pv[i];
            }
        }
        return root;
    }
};