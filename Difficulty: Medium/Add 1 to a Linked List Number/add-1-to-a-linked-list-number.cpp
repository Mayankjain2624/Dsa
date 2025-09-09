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
        // Node* newhead=reverseList(head);
        // int s=newhead->data+1;
        // newhead->data=s%10;
        // s=s/10;
        // if(newhead->next!=nullptr)
        // {
        // Node* temp=newhead->next;
        // while(temp){
        //     s=s+temp->data;
        //     temp->data=s%10;
        //     s=s/10;
        //     temp=temp->next;
        // }
        // if(s)
        // temp->next=new Node(s);
        // newhead=reverseList(newhead);
        // while(newhead->data==0)
        // newhead=newhead->next;
        // return newhead;
        // }
        // newhead->next=new Node(s);
        //  newhead=reverseList(newhead);
        //  while(newhead->data==0)
        // newhead=newhead->next;
        // return newhead;
        
        Node* newhead = reverseList(head);
        int carry = 0;
        Node* temp = newhead;
        if(temp->data == 9)
        {
            carry = 1;
            temp->data = 0;
        }
        else
        {
            temp->data = temp->data + 1;
        }
        while(temp->next != NULL && carry == 1)
        {
            temp = temp->next;
            if(temp->data == 9)
            {
                temp->data = 0;
            }
            else
            {
                temp->data = temp->data + 1;
                carry=0;
            }
        }
        if(carry == 1)
        {
            Node* newnode = new Node(1);
            temp->next = newnode;
        }
        return reverseList(newhead);
    }
};