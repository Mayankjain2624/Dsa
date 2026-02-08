/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool solve(Node* node){
        if(node->left==nullptr && node->right==nullptr)
        return true;
        bool l=true,r=true;
        int lv=0,rv=0;
        if(node->left!=nullptr)
        {
        l=solve(node->left);
        lv=node->left->data;
        }
        if(node->right!=nullptr){
        r=solve(node->right);
        rv=node->right->data;
        }
        if(l && r && (node->data==lv+rv))
         return true;
         
         else
         return false;
    }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
        
    }
};