class MyCircularDeque {
    struct node{
        int val; 
        node *next, *prev;
        node(int val){
            this->val = val;
            next = prev = NULL;
        }
    };
    node *head,*tail;
    int maxSize;
    int listSize;
public:
    MyCircularDeque(int k) {
        maxSize = k;
        listSize = 0;
        head = tail = NULL;
    }
    
    bool insertFront(int value) {
        if(listSize == maxSize){
            return false;       //Overflow
        }
        node* newnode = new node(value);
        if(!head){
            head = tail = newnode;
            head->next = tail;  // make it circular.
            tail->prev = head;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            tail->next = newnode;
            newnode->prev = tail;
            head = newnode;
        }
        listSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(listSize == maxSize){
            return false;      //Overflow.
        }
        node* newnode = new node(value);
        if(!head){
            head = tail = newnode;
            head->next = tail;
            tail->prev = head;
        }
        else{
            newnode->next = head;
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            head->prev = tail; 
        }
        listSize++;
        return true;
    }
    
    bool deleteFront() {
        if(listSize == 0){
            return false; // underflow;
        }
        if(listSize == 1){
            delete head;  //Avoiding memory leak.
            head = tail = NULL;
        }
        else{
            node* curr = head;
            head = head -> next;
            curr->next = curr->prev = NULL;
            head->prev = tail;
            tail->next = head;
            delete curr;  //Avoiding memory leak.
        }
        listSize--;
        return true;
    }
    
    bool deleteLast() {
        if(listSize == 0)
           return false;
        if(listSize == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            node* curr = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            curr->next = curr->prev = NULL;
            delete curr; // Avoiding memory leak.
        }
        listSize--;
        return true;
    }
    
    int getFront() {
        if(listSize == 0){
            return -1;
        }
        return head->val;
    }
    
    int getRear() {
        if(listSize == 0){
            return -1;
        }
        return tail->val;
    }
    
    bool isEmpty() {
        return listSize == 0;
    }
    
    bool isFull() {
        return listSize == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */