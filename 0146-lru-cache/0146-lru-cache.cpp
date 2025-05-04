class LRUCache {
public:
    class Node{
        public:
        int key; 
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this -> key = key;
            this -> val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*>mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node* newnode){
        Node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key) {

        if(mpp.find(key) != mpp.end()){
            Node* resnode = mpp[key];
            int ans = resnode -> val;
            mpp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mpp[key] = head -> next;
            return ans;
        }
        return -1;   
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* currnode = mpp[key];
            mpp.erase(key);
            deleteNode(currnode);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */