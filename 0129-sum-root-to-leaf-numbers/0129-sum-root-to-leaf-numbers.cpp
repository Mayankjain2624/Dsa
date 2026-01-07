class Solution {
public:
    int dfs(TreeNode* node,int num) {
        int left=0,right=0;
        if(node==nullptr)
        return 0;
        if(node->left==nullptr && node->right==nullptr)
        {
        num=num*10+node->val;
        return num;
        }
        left= dfs(node->left,num*10+node->val); 
        right=dfs(node->right,num*10+node->val);
        return left+right;
    }
    int sumNumbers(TreeNode* root) { return dfs(root,0); }
};