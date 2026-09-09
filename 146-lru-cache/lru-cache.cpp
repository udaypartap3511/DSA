class LRUCache {
public:
    class Node{
        public:
        int _key;
        int val;
        Node* next;
        Node* prev;
        Node(int key_,int val_){
            _key=key_;
            val=val_;
        }
    };
    
    int cap;
    unordered_map<int,Node*> mp;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){
        Node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode){
        Node* delNodePrev=delNode->prev;
        Node* delNodeNext=delNode->next;
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
    }
    
    int get(int key) {
       
       if(mp.find(key)!=mp.end()){
          Node* resNode=mp[key];
          int res= resNode->val;

          mp.erase(key);

          deleteNode(resNode);
          addNode(resNode);
          
          mp[key]=head->next;

          return res;
       }

       return -1;
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* resNode= mp[key];
            mp.erase(key);
            deleteNode(resNode);
        }
        if(cap==mp.size()){
            mp.erase(tail->prev->_key);
            deleteNode(tail->prev);
        }
        Node* newNode= new Node(key,value);
        addNode(newNode);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */