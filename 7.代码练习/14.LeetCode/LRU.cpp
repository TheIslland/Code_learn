class LRUCache {
public:
    class Node{
        public:
        Node (int a, int b) : key(a), val(b), pre(nullptr), next(nullptr){
        }
        public:
        int key;
        int val;
        Node *pre;
        Node *next;
    };
    class List {
        public:
        List() {
            size = 0;
            head = nullptr;
            tail = nullptr;
        }
        Node *insert_front(Node *node) {
            if (!head) {
                head = node;
                tail = node;
                size++;
                return head;
            }
            node->next = head;
            head->pre = node;
            head = node;
            size++;
            return head;
        }
        void erase(Node *node) {
            if (!node) return;
            size--;
            if (head == node) {
                head = node->next;
                node->pre = node->next = nullptr;
                //delete node;
                return ;
            }
            if (tail == node) {
                tail = node->pre;
                node->pre = node->next = nullptr;
                //delete node;
                return ;
            }
            node->pre->next = node->next;
            node->next->pre = node->pre;
            node->pre = node->next = nullptr;
            //delete node;
        }
        public:
        int size;
        Node *head;
        Node *tail;
    };
    LRUCache(int capacity) : count(capacity) {
        l = List();    
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            l.erase(mp[key]);
            l.insert_front(mp[key]);
            return mp[key]->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (l.size == count) {
                mp.erase(l.tail->key);
                l.erase(l.tail);
            }
            Node *temp = new Node(key, value);
            l.insert_front(temp);
            mp[key] = temp;
            return ;
        }
        mp[key]->val = value;
        l.erase(mp[key]);
        l.insert_front(mp[key]);
    }
    unordered_map<int, Node *> mp;
    List l;
    int count;
};