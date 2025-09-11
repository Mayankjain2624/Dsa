/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node* reverseList(Node* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* newhead=reverseList(head->next);
        Node* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
    Node* addOne(Node* head) {
       Node* newhead=reverseList(head);
       int carry=0;
       Node* temp=newhead;
       Node* prev=nullptr;
       while(temp){
           if(temp->data==9){
               temp->data=0;
               carry=1;
               prev=temp;
               temp=temp->next;
           }
           else
           {
               temp->data=temp->data+1;
               carry=0;
               break;
           }
       }
       if(carry){
           prev->next=new Node(1);
       }
       head=reverseList(newhead);
       return head;
    }
};