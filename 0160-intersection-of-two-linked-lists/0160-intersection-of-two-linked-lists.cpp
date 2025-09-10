/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0;
        int c2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1){
            c1++;
            temp1=temp1->next;
        }
        while(temp2){
            c2++;
            temp2=temp2->next;
        }
            temp1=headA;
            temp2=headB;
        if(c1>c2){
            int d=c1-c2;
            while(d--){
                temp1=temp1->next;
            }
            while(temp1 && temp2){
                if(temp1==temp2)
                return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        else
        {
            int d=c2-c1;
            while(d--){
                temp2=temp2->next;
            }
            while(temp1 && temp2){
                if(temp1==temp2)
                return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return nullptr;
    }
};