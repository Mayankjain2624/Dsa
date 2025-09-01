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
    ListNode *detectCycle(ListNode *head) {
                   unordered_map<ListNode*,int>mp;
            ListNode* temp=head;
            int cnt=0;
            while(temp){
                cnt++;
                if(mp[temp])
                return temp;
                mp[temp]=cnt;
                temp=temp->next;
            }
          return nullptr;

    }
};