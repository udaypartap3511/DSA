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
    bool hasCycle(ListNode *head) {
        
        ListNode* l1=head;
        ListNode* l2=head;
        while(l1!=nullptr && l1->next!=nullptr){
            l1=l1->next->next;
            l2=l2->next;
            if(l1==l2){
                return true;
            }
        }

        return false;
    }
};