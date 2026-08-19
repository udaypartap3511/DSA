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

        ListNode* slow=headA;
        ListNode* fast=headB;

        while(fast!=slow){
            if(fast==nullptr){
                fast=headA;
            }
            else{
                fast=fast->next;
            }
            if(slow==nullptr){
                slow=headB;
            }

            else{
                slow=slow->next;
            }
            
        }

        return slow;
        
    }
};