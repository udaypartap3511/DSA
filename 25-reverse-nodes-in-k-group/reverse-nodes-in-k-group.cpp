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
            ListNode* nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }

        return prev;
    }
    ListNode* kthNode(ListNode* temp,int k){
        k--;
        while(k-- && temp!=nullptr){
            temp=temp->next;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode= kthNode(temp,k);
            if(kthnode==nullptr){
                if(prevnode!=nullptr) prevnode->next=temp;
                return head;
            } 

            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;

            reversenode(temp);

            if(temp==head){
                head=kthnode;
            }
            else{
               prevnode->next=kthnode;
            }
            

            prevnode=temp;
            temp=nextnode;
            
        }
        
        return head;
    }
};