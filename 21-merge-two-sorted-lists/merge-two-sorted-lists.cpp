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
        
        ListNode* d=new ListNode(-1);
        ListNode* dd=d;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                dd->next=list1;
                list1=list1->next;
            }
            else{
                dd->next=list2;
                list2=list2->next;
            }
            dd=dd->next;
        }
        if(list1!=nullptr){
            dd->next=list1;
        }
        else{
            dd->next=list2;
        }
      
      return d->next;
    }
};