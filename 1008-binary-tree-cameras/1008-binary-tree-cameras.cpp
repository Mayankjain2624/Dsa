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
    int ans = 0;
    unordered_set<TreeNode*> cover;
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node == nullptr)
            return;
        TreeNode* rchild = node->right;
        TreeNode* lchild = node->left;
        bool leaf = false, root = false;
        if (rchild == nullptr && lchild == nullptr)
            leaf = true;
        if (parent == nullptr)
            root = true;
        dfs(rchild, node);
        dfs(lchild, node);
        if ( !leaf &&
            ((rchild != nullptr && cover.count(rchild) == 0) ||
             (lchild && cover.count(lchild) == 0))) {
            ans++;
            if(parent!=nullptr)
            cover.insert(parent);
            cover.insert(node);
            if (rchild != nullptr)
                cover.insert(rchild);
            if (lchild != nullptr)
                cover.insert(lchild);
        }
    }
    int minCameraCover(TreeNode* root) {
        dfs(root, nullptr);
        // if(cover.find(root->left))
        if (cover.find(root) == 0)
            ans++;
        
        return ans;
    }
};