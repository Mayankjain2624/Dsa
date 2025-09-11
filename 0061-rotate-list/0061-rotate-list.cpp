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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = head;
        if(head==nullptr || head->next==nullptr)
        return head;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        k=k%cnt;
        int x = cnt - k;
        temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
        temp = head;
        int c = 0;
        while (temp) {
            c++;
            if (c == x) {
                head = temp->next;
                temp->next = nullptr;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};