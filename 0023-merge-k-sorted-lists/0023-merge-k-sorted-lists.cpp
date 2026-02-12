class Solution {
public:
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // min-heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        for(auto &it:lists){
            if(it!=nullptr)
            pq.push(it);
        }
        ListNode* dummyhead=new ListNode(0);
        ListNode* curr=dummyhead;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next!=nullptr)
            pq.push(node->next);
       }
      return dummyhead->next;
    }
};