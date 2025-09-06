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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        int k = cnt - n + 1;
        if(k==1)
        {
            head=head->next;
            return head;
        }
        temp = head;
        if (k == cnt) {
            while (temp->next->next) {
                temp = temp->next;
            }
            ListNode* t=temp->next;
            temp->next=nullptr;
            delete t;
            return head;
        }
        temp = head;
        cnt = 1;
        ListNode* prev=temp;
        while (temp) {
            if (cnt == k) {
                prev->next=temp->next;
                delete temp;
                break;
            }
            prev=temp;
            temp = temp->next;
            cnt++;
        }
        return head;
    }
};