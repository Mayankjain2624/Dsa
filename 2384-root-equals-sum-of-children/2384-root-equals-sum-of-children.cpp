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
    bool checkTree(TreeNode* root) {
        queue<TreeNode*>q;
         if(root!=nullptr)
         q.push(root);
         while(!q.empty()){
             TreeNode* node=q.front();
             q.pop();
             int sum=0;
             int flag=0;
             if(node->left!=nullptr)
             {
                 flag=1;
                 sum+=node->left->val;
                 q.push(node->left);
             }
             if(node->right!=nullptr)
             {
                 flag=1;
                 sum+=node->right->val;
                 q.push(node->right);
             }
              if(flag && node->val!=sum)
              return false;
         }
         return true;
    }
};