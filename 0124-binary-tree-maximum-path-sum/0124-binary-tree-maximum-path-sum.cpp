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
    int maxi = -1e9;
    int depth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int l = max(0,depth(node->left));
        int r = max(0,depth(node->right));
        maxi = max(maxi, node->val+l + r);
        cout<<maxi<<endl;
        return node->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
         depth(root);
        return maxi;
    }
};