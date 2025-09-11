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
        if(headA==headB)
        return headA;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(true){
            if(temp1==temp2)
            return temp1;
            else if(temp1->next==nullptr && temp2->next==nullptr)
            return nullptr;
            else
            {
                if(temp1->next)
                temp1=temp1->next;
                else
                temp1=headB;
                if(temp2->next)
                temp2=temp2->next;
                else
                temp2=headA;
            }
        }
        return nullptr;
    }
};