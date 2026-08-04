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
        ListNode* dummy=new ListNode(-1,head);
        ListNode* slow=dummy;
        ListNode* fast=dummy;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* Next=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(Next!=nullptr){
            ListNode* ne=Next->next;
            Next->next=prev;
            prev=Next;
            Next=ne;
        }

        slow->next=prev;
        slow=slow->next;

        fast=head;

        while(slow!=nullptr){
             if(slow->val!=fast->val){
                return false;
            }
            fast=fast->next;
            slow=slow->next;
            
           
            
        }

        return true;

        
    }
};