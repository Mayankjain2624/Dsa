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
    void deleteNode(ListNode* node) {
        int val=node->val;
        ListNode* par=node;
        node=node->next;
        while(node!=nullptr)
        {
            if(node->next==nullptr)
            {
                par->val=node->val;
                par->next=nullptr;
                break;
            }
            else{
        par->val=node->val;
        par=par->next;
        node=node->next;
            }
        }
    }
};