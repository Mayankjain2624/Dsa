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
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &x, int si,
                    int ei) {
        if (si > ei)
            return nullptr;
        if (x >= (int)preorder.size())
        return nullptr;
        int val = preorder[x];
        TreeNode* root = new TreeNode(val);
        x++;
       auto it =
            find(inorder.begin()+si, inorder.end()+ei+1,val);
            if(*it!=val || it==inorder.begin()+ei+1)
            return root;
            int ri=it-inorder.begin();
        TreeNode* lchild = solve(preorder, inorder, x, si, ri - 1);
        TreeNode* rchild = solve(preorder, inorder, x, ri + 1, ei);
        root->left = lchild;
        root->right = rchild;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int x=0;
        return solve(preorder, inorder, x, 0, (int)inorder.size() - 1);
    }
};