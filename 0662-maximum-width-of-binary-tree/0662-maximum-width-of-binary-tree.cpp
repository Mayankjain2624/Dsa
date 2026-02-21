/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long int val;
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 1});
        long long int ans = 1;
        long long int pw = 0;
        while (!q.empty()) {
            long long int n = q.size();
            long long int maxi=0,mini=LLONG_MAX;
            int k=q.front().second;
            while (n--) {
                TreeNode* node = q.front().first;
                long long int par = q.front().second-k;
                q.pop();
                maxi=max(maxi,par);
                mini=min(mini,par);
                if(node->left!=nullptr){
                    q.push({node->left,2*par});
                }
                if(node->right!=nullptr){
                    q.push({node->right,2*par+1});
                }
            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};