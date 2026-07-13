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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* l1=list1;
        ListNode* l2=list2;

        ListNode* dummy=new ListNode(-1);
        ListNode* dd=dummy;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                dd->next=l1;
                l1=l1->next;
                dd=dd->next;
            }
            else{
                dd->next=l2;
                l2=l2->next;
                dd=dd->next;
            }
        }

        if(l2){
            dd->next=l2;
        }
        if(l1){
            dd->next=l1;
        }

        return dummy->next;
        
    }
};