/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

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
        while(temp!=nullptr)
        {
            Node* copy=temp->next;
            if(temp->random!=nullptr)
            copy->random=temp->random->next;
            else
            copy->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp!=nullptr)
        {
            res->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            res=res->next;
        }
        return dummy->next;
    }
};