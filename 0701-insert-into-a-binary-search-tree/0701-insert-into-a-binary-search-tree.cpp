class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
                     TreeNode* rr=new TreeNode(val);
                     if(root==nullptr)
                     return rr;
        while(root){
            if(root->val<val){
                if(root->right==nullptr)
                {
                     root->right=rr;
                     break;
                }
                else
                {
                root=root->right;
                }
            }
            else
            {
            if(root->left==nullptr){
            root->left=rr;
            break;

            }
            else
            root=root->left;
            }
        }
        return temp;
    }
};
