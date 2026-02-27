class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache
{
public:
    unordered_map<int, Node *> mp;
    Node *head, *tail;
    int cap = 0;
    void deleteNode(Node *add)
    {
        Node *nextNode = add->next;
        Node *prevNode = add->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        add->next = nullptr;
        add->prev = nullptr;
        // delete add;
    }
    void insertAthead(Node *add)
    {
        Node *nextNode = head->next;
        add->next = nextNode;
        add->prev = head;
        head->next = add;
        nextNode->prev = add;
    }
    LRUCache(int cap)
    {
        // code here
        this->cap = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node* add=mp[key];
            deleteNode(add);
            insertAthead(add);
            return add->val;
        }
        return -1;

    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            Node* add=mp[key];
            add->val=value;
            deleteNode(add);
            insertAthead(add);
        }
        else{
            Node* newNode=new Node(key,value);
            mp[key]=newNode;
            insertAthead(newNode);
            if(mp.size()>cap){
                Node* lru=tail->prev;
                int k=lru->key;
                deleteNode(lru);
                delete lru;
                mp.erase(k);

            }
        }
    }
};