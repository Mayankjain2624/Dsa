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
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode* head=new ListNode(-1);
        ListNode* ans=head;
        int sum=0;
        while(t1 || t2){
            if(t1){
                sum+=t1->val;
                t1=t1->next;
            }
            if(t2){
                sum+=t2->val;
                t2=t2->next;
            }
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            sum/=10;
        }
        while(sum)
        {
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            sum/=10;
        }
        return head->next;
    }
};