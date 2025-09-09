/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
Node* merge(Node* list1, Node* list2) {
        Node* dummy=new Node(-1);
        Node* t1=list1;
        Node* t2=list2;
        Node* temp=dummy;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->data<=t2->data)
            {
               temp->next=t1;
               t1=t1->next;
               temp=temp->next;
            }
            else
            {
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
            }
        }
        if(t1)
        temp->next=t1;
        if(t2)
        temp->next=t2;
        return dummy->next;
    }
    Node* findmid(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* segregate(Node* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        Node* mid=findmid(head);
        Node* head2=mid->next;
        mid->next=nullptr;
        Node* head1=head;
        head1=segregate(head1);
        head2=segregate(head2);
        return merge(head1,head2);
    }
};



