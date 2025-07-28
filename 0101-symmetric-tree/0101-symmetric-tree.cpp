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
        // vector<vector<int>>ans;
        vector<int> level, lc;
        if (root == nullptr)
            return true;
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
            lc = level;
            reverse(lc.begin(), lc.end());
            if (lc != level)
                return false;
            level.clear();
            lc.clear();
        }
        return true;
    }
};