class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        bool k = true;
        queue<TreeNode*> q;
        q.push(root);

        deque<int> temp;
        while (!q.empty()) {
            int n = q.size();
            temp.clear();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                if (k)
                    temp.push_back(node->val);
                else
                    temp.push_front(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.emplace_back(temp.begin(), temp.end());
            k = !k;
        }

        return ans;
    }
};
