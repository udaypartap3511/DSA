/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reversenode(ListNode* temp){
        ListNode* prev=nullptr;

        while(temp!=nullptr){
            ListNode* Next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=Next;
        }
        return prev;
    }
    ListNode* kthNode(ListNode* temp,int k){
        k--;
        while(temp!=nullptr && k!=0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode=kthNode(temp,k);
            if(kthnode==nullptr){
                if(prevnode!=nullptr) prevnode->next=temp;
                return head;
            }
            ListNode* Nextnode=kthnode->next;
            kthnode->next=nullptr;
            reversenode(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=Nextnode;
        }
        return head;
        
    }
};