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
 class BSTIteratord {
public:
TreeNode* it;
stack<TreeNode*>st;
    BSTIteratord(TreeNode* root) { 
        while(root!=nullptr)
        {
            st.push(root);
            root=root->right;
        }
    }
    
    int next() {
         auto top=st.top();
         st.pop();
         it=top->left;
         while(it!=nullptr)
         {
            st.push(it);
            it=it->right;
         }
         return top->val;
    }
    
    bool hasNext() {
        if(!st.empty())
        return true;
        return false;
    }
};
class BSTIteratora {
public:
TreeNode* it;
stack<TreeNode*>st;
    BSTIteratora(TreeNode* root) {
        // st.push(root);
        // it=root;    
        while(root!=nullptr)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
         auto top=st.top();
         st.pop();
         it=top->right;
         while(it!=nullptr)
         {
            st.push(it);
            it=it->left;
         }
         return top->val;
    }
    
    bool hasNext() {
        if(!st.empty())
        return true;
        return false;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
          BSTIteratora as=BSTIteratora(root);
          BSTIteratord ds=BSTIteratord(root);
          int a=as.next();
          int b=ds.next();
          while(true){
            if(a+b==k && a!=b)
            return true;
            else if(a+b>k)
            {
                if(ds.hasNext())
                b=ds.next();
                else
                break;
            }
            else
            {
                if(as.hasNext())
                a=as.next();
                else
                break;
            }
          }
          return false;
    }
};