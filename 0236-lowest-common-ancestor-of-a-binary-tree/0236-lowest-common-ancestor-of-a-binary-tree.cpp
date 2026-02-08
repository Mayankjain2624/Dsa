class Solution {
public:
    vector<TreeNode*> pv, qv;
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node==p || node==q ||node==nullptr)
        return node;
        TreeNode* left=solve(node->left,p,q);
        TreeNode* right=solve(node->right,p,q);
        if(left==nullptr)
        return right;
        else if(right==nullptr)
        return left;
        else
        return node;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p,q);
        
    }
};