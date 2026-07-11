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
    ListNode* reversenode(ListNode* Next){

        ListNode* prev=nullptr;
        while(Next!=nullptr){
            ListNode* Ne=Next->next;
            Next->next=prev;
            prev=Next;
            Next=Ne;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        if(fast->next!=nullptr){
            fast=fast->next;
        }
        
        ListNode* Next=slow->next;
        slow->next=nullptr;

        reversenode(Next);

        slow->next=fast;
        slow=head;
        while(fast!=nullptr){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }

        return true;
        
    }
};