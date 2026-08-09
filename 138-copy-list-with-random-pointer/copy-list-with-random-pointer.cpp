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

        while(temp!=nullptr){
           Node* Next=temp->next;
           Node* copy=new Node(temp->val);
           temp->next=copy;
           copy->next=Next;
           temp=temp->next->next;
        }

        temp=head;
        while(temp!=nullptr){
           if(temp->random==nullptr) temp->next->random=nullptr;
           else temp->next->random=temp->random->next;
           temp=temp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* dd=dummy;

        temp=head;
        while(temp!=nullptr){
            dummy->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            dummy=dummy->next;
        }

        return dd->next;
        
    }
};