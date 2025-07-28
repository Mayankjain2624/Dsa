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
    bool isSymmetric(TreeNode* root) {
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr)
                    level.push_back(INT_MIN);
                else {
                    q.push(node->left);
                    q.push(node->right);
                    level.push_back(node->val);
                }
            }
            for (int i = 0; i < level.size() / 2; i++) {
                if (level[i] != level[level.size() - 1 - i])
                    return false;
            }
            level.clear();
        }
        return true;
    }
};