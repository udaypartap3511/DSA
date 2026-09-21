class LFUCache {
public:
    class node{
        public:
        int _val;
        int _key;
        int cnt;
        node* next;
        node* prev;
        node(int key,int val){
            _key=key;
            _val=val;
            cnt=1;
        }
    };

    int cap;
    unordered_map<int,node*> cacheMap;
    unordered_map<int,pair<node*,node*>> freqMap;
    int minFreq;

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }

    void addNode(node* newNode,int freq){
        if(freqMap.find(freq)==freqMap.end()){
            node* head=new node(-1,-1);
            node* tail=new node(-1,-1);
            freqMap[freq]={head,tail};
            head->next=tail;
            tail->prev=head;
        }

        node* head=freqMap[freq].first;
        node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void remove(node* delNode){
        node* delNodePrev=delNode->prev;
        node* delNodeNext=delNode->next;
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
    }
    
    void updateFreq(node* node){
        int oldFreq=node->cnt;
        node->cnt++;

        remove(node);

        if(freqMap[oldFreq].first->next==freqMap[oldFreq].second){
            freqMap.erase(oldFreq);

            if(minFreq==oldFreq){
            minFreq++;
            }
        }

        addNode(node,node->cnt);
    }
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()){
            return -1;
        }
        node* resNode=cacheMap[key];
        int res=resNode->_val;
        updateFreq(resNode);
        return res;
    }
    
    void put(int key, int value) {
        
        if(cap==0){
            return;
        }
        if(cacheMap.find(key)!=cacheMap.end()){
           node* resNode=cacheMap[key];
           resNode->_val=value;
           updateFreq(resNode);
        }
        else{
            if(cacheMap.size()==cap){
                node* delNode=freqMap[minFreq].second->prev;
                remove(delNode);
                cacheMap.erase(delNode->_key);

                if(freqMap[minFreq].first->next==freqMap[minFreq].second){
                    freqMap.erase(minFreq);
                }
                delete delNode;
            }
            
            node* newnode=new node(key,value);
            cacheMap[key]=newnode;
            addNode(newnode,1);
            minFreq=1;
        
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */