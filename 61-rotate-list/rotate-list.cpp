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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr){
            return nullptr;
        }
        
        int n=0;
        ListNode* fast=head;
        while(fast!=nullptr){
            n++;
            fast=fast->next;
        }

        if(k%n==0){
            return head;
        }
        fast=head;
        ListNode* slow=head;

        for(int i=0;i<k%n;i++){
           fast=fast->next;
        }

        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newh=slow->next;
        slow->next=nullptr;
        fast->next=head;

        return newh;
    }
};