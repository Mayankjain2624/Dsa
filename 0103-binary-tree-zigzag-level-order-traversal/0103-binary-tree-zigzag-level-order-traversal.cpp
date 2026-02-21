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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int k = 0;
        queue<TreeNode*> q;
        q.push(root);
        if (root == nullptr)
            return ans;
        while (!q.empty()) {
            int n = q.size();
        vector<int> temp(n);
        int i=n-1;
        int oi=0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                    if(k&1)
                    temp[i--]=node->val;
                    else
                    temp[oi++]=node->val;
            }
            ans.push_back(temp);
            k++;
        }
        return ans;
    }
};