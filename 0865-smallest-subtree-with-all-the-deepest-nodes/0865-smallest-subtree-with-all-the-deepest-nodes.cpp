/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
TreeNode* LCA(TreeNode* root, int d, int maxd) {
    if (root == NULL)
        return root;

    if (d == maxd)
        return root;
    TreeNode* left = LCA(root->left, d + 1, maxd);
    TreeNode* right = LCA(root->right, d + 1, maxd);

    if (left && right)
        return root;
    return left ? left : right;
}

void depth(TreeNode* root, int d, int& maxd) {
    if (root == NULL)
        return;
    maxd = max(maxd, d);
    depth(root->left, d + 1, maxd);
    depth(root->right, d + 1, maxd);
}

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxD = 0;

        depth(root, 0, maxD);

        return LCA(root, 0, maxD);
    }
};