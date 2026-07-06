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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==nullptr){
            return nullptr;
        }
        
       int cnt=0;
    //    ListNode* slow=head;
    //    ListNode* fast=head;
    //    while(fast!=nullptr && fast->next!=nullptr){
    //     fast=fast->next->next;
    //     slow=slow->next;
    //     cnt++;
    //    }
      ListNode* temp=head;
      while(temp!=nullptr){
        cnt++;
        temp=temp->next;
      }
      if(cnt==n){
        return head->next;
      }
      int tr=cnt-(n+1);
      temp=head;
      for(int i=0;i<tr;i++){
         temp=temp->next;
      }

      ListNode* curr=temp->next;
      temp->next=temp->next->next;
      curr->next=nullptr;

      return head;
       
    }
};