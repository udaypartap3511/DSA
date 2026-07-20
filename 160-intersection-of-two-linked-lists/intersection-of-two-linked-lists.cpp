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

        ListNode* dummy=new ListNode(0,headA);
        ListNode* dd=new ListNode(0,headB);

        ListNode* fast=headA;
        ListNode* slow=headB;

        while(fast!=slow){
            if(fast==nullptr){
                fast=dd;
            }
            if(slow==nullptr){
                slow=dummy;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};