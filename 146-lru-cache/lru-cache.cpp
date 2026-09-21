class LRUCache {
public:
    class node{
        public:
        int _key;
        int _val;
        node* next;
        node* prev;
        node (int key,int val){
             _key=key;
             _val=val;
        }
    };

    int cap;
    unordered_map<int,node*> mp;
    node* head=new node(-1,-1);
    node* last=new node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=last;
        last->prev=head;
    }

    void addNode(node* newNode){
        node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void deleteNode(node* delNode){
        node* delNodePrev=delNode->prev;
        node* delNodeNext=delNode->next;
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        node* nodeadd=mp[key];
        int res=nodeadd->_val;
        mp.erase(key);

        deleteNode(nodeadd);
        addNode(nodeadd);
        mp[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* resnode=mp[key];
            deleteNode(resnode);
            mp.erase(key);
        }

        if(mp.size()==cap){
            mp.erase(last->prev->_key);
            deleteNode(last->prev);
        }
        
        node* newNode=new node(key,value);
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