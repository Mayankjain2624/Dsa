/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* temp=dummy;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<=t2->val)
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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* mid=findmid(head);
        ListNode* head2=mid->next;
        mid->next=nullptr;
        ListNode* head1=head;
        head1=sortList(head1);
        head2=sortList(head2);
        return merge(head1,head2);
    }
};