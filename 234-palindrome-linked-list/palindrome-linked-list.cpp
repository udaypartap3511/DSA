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
    bool isPalindrome(ListNode* head) {
        
       if(head==nullptr || head->next==nullptr){
        return true;
       }
        ListNode* dummy= new ListNode(-1,head);

        ListNode* fast=dummy;
        ListNode* slow=dummy;

        while(fast!=nullptr && fast->next!=nullptr){
          fast=fast->next->next;
          slow=slow->next;
        }

        ListNode* slownext=slow->next;
        ListNode* prev=nullptr;

        while(slownext!=nullptr){
            ListNode* nextnode=slownext->next;
            slownext->next=prev;
            prev=slownext;
            slownext=nextnode;
        }

        fast=head;
        while(prev!=nullptr){
            if(prev->val!=fast->val){
                return false;
            }

            prev=prev->next;
            fast=fast->next;
        }

        return true;
    }
};