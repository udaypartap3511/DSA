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
            Node* curr=new Node(temp->val);
            Node* Next=temp->next;
            temp->next=curr;
            curr->next=Next;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->random){
            temp->next->random=temp->random->next;}
            
            else{
                temp->next->random=nullptr;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* dd=dummy;
        while(temp!=nullptr){
            dummy->next=temp->next;
            dummy=dummy->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }

        return dd->next;
        
    }
};