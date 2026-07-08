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
        
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* nextNode=slow->next;
        slow->next==nullptr;
        ListNode* prev=nullptr;

        while(nextNode!=nullptr){
            ListNode* Next=nextNode->next;
            nextNode->next=prev;
            prev=nextNode;
            nextNode=Next;
        }
        slow->next=prev;

        fast=head;

        while(prev!=nullptr){
            if(fast->val!=prev->val){
                return false;
            }
            fast=fast->next;
            prev=prev->next;
        }

        return true;

    }
};