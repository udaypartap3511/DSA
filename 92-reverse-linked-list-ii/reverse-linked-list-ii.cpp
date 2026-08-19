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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==nullptr || left==right){
            return head;
        }

        ListNode* dummy=new ListNode(-1,head);
        
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        ListNode* prev=dummy;
       
       for(int i=1;i<=left-1;i++){
            
            prev=prev->next;
        }

        for(int i=1;i<=left;i++){
            
            slow=slow->next;
        }

        for(int i=1;i<=right;i++){
           fast=fast->next;
        }

         ListNode* fastn=fast->next;

         prev->next=nullptr;
         ListNode* start=slow;
         

         ListNode* prevnode=nullptr;
         while(slow!=fastn){
            ListNode* nextnode=slow->next;
            slow->next=prevnode;
            prevnode=slow;
            slow=nextnode;
         }

         prev->next=prevnode;
         start->next=fastn;


         return dummy->next;

    }
};