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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=nullptr){
            int val=curr->val;
            if(st.count(val))
            {
                ListNode* temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                temp->next=nullptr;
                // delete temp;
            }
            else
            {
                prev=prev->next;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};