/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp=head;
        unordered_map<Node*,Node*> mp;
        while(temp!=nullptr){
            Node* curr=new Node(temp->val);
            mp[temp]=curr;
            temp=temp->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        while(temp!=nullptr){
            dummy->next=mp[temp];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
            dummy=dummy->next;
            
        }
        

        return mp[head];
        
    }
};