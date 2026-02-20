/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* hc=head;
        Node* temp=head;
        while(true){
            Node* front=temp->next;
            Node* back=temp->prev;
            temp->next=back;
            temp->prev=front;
            if(front==nullptr)
            break;
            temp=front;
        }
        return temp;
    }
};