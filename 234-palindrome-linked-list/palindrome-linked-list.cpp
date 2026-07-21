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

        ListNode* curr=slow->next;
        slow->next=nullptr;

        ListNode* prev=nullptr;

        while(curr!=nullptr){
            ListNode* Next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }

        slow->next=prev;
        slow=slow->next;
        fast=head;
        while(slow!=nullptr){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};