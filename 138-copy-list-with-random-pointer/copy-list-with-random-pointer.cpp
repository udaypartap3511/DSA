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
            Node* curr=new Node(temp->val);
            temp->next=curr;
            curr->next=Next;
            temp=temp->next->next;
        }

        temp=head;

        while(temp!=nullptr){
            if(temp->random==nullptr){
                temp->next->random=nullptr;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* dd=dummy;

        temp=head;
        while(temp!=nullptr){
            dd->next=temp->next;
            temp->next=temp->next->next;
            dd=dd->next;
            temp=temp->next;
        }

        return dummy->next;
        
    }
};