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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue<int,vector<int>,greater<>>>>ds;
        queue<tuple<TreeNode* ,int,int>>q;
        q.push(make_tuple(root,0,0));
        while(!q.empty()){
            TreeNode* node=get<0>(q.front());
            int x=get<1>(q.front());
            int y=get<2>(q.front());
            q.pop();
            ds[y][x].push(node->val);
            if(node->left!=nullptr)
            q.push(make_tuple(node->left,x+1,y-1));
            if(node->right!=nullptr)
            q.push(make_tuple(node->right,x+1,y+1));
        }
         vector<vector<int>>ans;
         for(auto &it:ds){
            int col=it.first;
            auto mpp=it.second;
            vector<int>colv;
            for(auto &it1:mpp){
                int row=it1.first;
                auto tb=it1.second;
                while(!tb.empty()){
                      colv.push_back(tb.top());
                      tb.pop();
                }
            }
            ans.push_back(colv);
         }
         return ans;
    }
};