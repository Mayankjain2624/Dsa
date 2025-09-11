// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int x) {
        // code here
        vector<pair<int, int>>ans;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        Node* tail=temp;
        temp=head;
        while(temp!=tail){
            int sum=temp->data+tail->data;
            if(sum==x)
            {
                ans.push_back({temp->data,tail->data});
            }
            if(sum>x){
                tail=tail->prev;
            }
            else
            temp=temp->next;
        }
        return ans;
    }
};