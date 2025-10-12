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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << slow->val << endl;
                ListNode* s1 = head;
                while (slow != s1) {
                    slow = slow->next;
                    s1 = s1->next;
                }
                return s1;
            }
        }
        return nullptr;
    }
};