/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isLeaf(Node* node){
      if(node->left==nullptr && node->right==nullptr)
      return true;
      return false;
  }
  void collectLeft(Node* node,vector<int>&res){
      if(node==nullptr || isLeaf(node) )
      return;
      res.push_back(node->data);
      if(node->left)
      collectLeft(node->left,res);
      else if(node->right)
      collectLeft(node->right,res);
  }
  void collectLeaf(Node* node,vector<int>&res){
      if(node==nullptr)
      return;
      if(isLeaf(node))
      res.push_back(node->data);
      collectLeaf(node->left,res);
      collectLeaf(node->right,res);
  }
  void collectRight(Node* node,vector<int>&res){
      if(node==nullptr || isLeaf(node))
      return;
      if(node->right)
      collectRight(node->right,res);
      else if(node->left)
      collectRight(node->left,res);
      res.push_back(node->data);
      
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
            if (!root)
             return res;
        if (!isLeaf(root))
        res.push_back(root->data);
        collectLeft(root->left,res);
        collectLeaf(root,res);
        collectRight(root->right,res);
        return res;
        
    }
};