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
 ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newhead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=nullptr && fast->next->next!=nullptr){
             slow=slow->next;
             fast=fast->next->next;
       }
       ListNode* newhead=reverseList(slow->next);
       ListNode* first=head;
       ListNode* second=newhead;
       while(second!=nullptr){
            if(first->val!=second->val)
            return false;
            first=first->next;
            second=second->next;
    }
    reverseList(slow->next);
 return true;
    }
};
//tc o(n)
//sc= O(1)