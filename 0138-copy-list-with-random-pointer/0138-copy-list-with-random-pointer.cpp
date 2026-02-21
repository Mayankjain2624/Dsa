class Solution {
public:
    Node* copyRandomList(Node* head) {
        //make and insert node
        //handle random pointer
        //handle next pointer
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->random!=nullptr)
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* ct=dummy;
        while(temp!=nullptr){
           Node* copy=temp->next;
           ct->next=copy;
           temp->next=copy->next;
           temp=temp->next;
        //    copy->next=nullptr;
           ct=copy;
        }
        return dummy->next;
    }
};