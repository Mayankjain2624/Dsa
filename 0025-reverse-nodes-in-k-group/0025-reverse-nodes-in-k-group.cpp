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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        temp = head;
        ListNode* oghead = head;
        ListNode* prevstart = new ListNode(-1);
        ListNode* start = head;
        int nr = 0;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            if (cnt == k) {
                nr++;
                ListNode* front = temp->next;
                temp->next = nullptr;
                ListNode* newhead = reverseList(start);
                prevstart->next = newhead;
                prevstart = start;
                start = front;
                temp = front;
                cnt = 0;
                if (nr == 1) {
                    head = newhead;
                }
            } else
                temp = temp->next;
        }
        prevstart->next=start;
        return head;
    }
};