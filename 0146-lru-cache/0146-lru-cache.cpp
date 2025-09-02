class LRUCache {
public:
    struct Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int cap = 0;
    void deleteNode(Node* node) {
        Node* pnode = node->prev;
        Node* nnode = node->next;
        pnode->next = nnode;
        nnode->prev = pnode;
        // delete pnode;
    }
    void insertAtHead(Node* node) {
        Node* nnode = head->next;
        head->next = node;
        node->prev = head;
        nnode->prev = node;
        node->next = nnode;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            node->value = value;
            insertAtHead(node);
        } else {
            if (mp.size() == cap) {
                Node* node = tail->prev;
                deleteNode(node);
                mp.erase(node->key);
                delete node;
            }
            Node* newnode = new Node(key, value);
            insertAtHead(newnode);
            mp[key]=newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */