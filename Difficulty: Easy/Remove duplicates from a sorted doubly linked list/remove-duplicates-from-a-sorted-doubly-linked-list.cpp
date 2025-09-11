/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head==nullptr || head->next==nullptr)
        return head;
        Node* temp=head->next;
        while(temp){
            Node* next=temp->next;
                Node* prev=temp->prev;
            if(temp->data==temp->prev->data)
            {
                prev->next=next;
                if(temp->next)
                next->prev=prev;
                delete temp;
            }
            temp=next;
        }
        return head;
    }
};