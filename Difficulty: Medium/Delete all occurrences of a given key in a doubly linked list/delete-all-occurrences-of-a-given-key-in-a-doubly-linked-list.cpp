// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
         Node* head=*head_ref;
         Node* temp=head;
         while(temp){
             Node* next=temp->next;
             if(temp->data==x){
                    if(temp->prev==nullptr){
                        *head_ref=temp->next;
                        if(*head_ref){
                            (*head_ref)->prev=nullptr;
                        }
                    }
                    else{
                        temp->prev->next=next;
                        if(next)
                        next->prev=temp->prev;
                    }
                    free(temp);
             }
             temp=next;
         }
    }
};