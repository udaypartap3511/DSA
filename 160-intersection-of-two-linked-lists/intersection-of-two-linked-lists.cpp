/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* fast=headA;
        ListNode* slow=headB;
        
        while(fast!=slow){
           if(fast==nullptr){
            fast=headB;
           }
           else{
             fast=fast->next;
           }
           if(slow==nullptr){
            slow=headA;
           }
           else{
            slow=slow->next;
           }
        }
        return slow;
    }
};