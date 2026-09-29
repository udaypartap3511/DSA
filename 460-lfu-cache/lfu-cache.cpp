class LFUCache {
public:
    class node{
        public:
        int _key;
        int _val;
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

     void addNode(node* newNode,int freq){

        if(freqMap.find(freq)==freqMap.end()){
            node* head= new node(-1,-1);
            node* tail= new node(-1,-1);
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

     void deleteNode(node* delNode){
        node* delNodePrev= delNode->prev;
        node* delNodeNext= delNode->next;
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
     }

     void updateFreq(node* node){
        int oldFreq=node->cnt;
        node->cnt++;

        deleteNode(node);

        if(freqMap[oldFreq].first->next==freqMap[oldFreq].second){
            freqMap.erase(oldFreq);

            if(oldFreq==minFreq){
                minFreq++;
            }
        }

        addNode(node,node->cnt);
     }

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=1;
    }
    
    int get(int key) {
        if(cacheMap.find(key)!=cacheMap.end()){
           node* node=cacheMap[key];
           int res=node->_val;
           updateFreq(node);
           return res;
        }

        return -1;
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
                node* delNode= freqMap[minFreq].second->prev;
                deleteNode(delNode);
                cacheMap.erase(delNode->_key);

                if(freqMap[minFreq].first->next==freqMap[minFreq].second){
                    freqMap.erase(minFreq);
                }
            }

            node* newNode= new node(key,value);
            addNode(newNode,1);
            cacheMap[key]=newNode;
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