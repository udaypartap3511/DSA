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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr){
            return nullptr;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* cnt=head;
        int ns=0;
        while(cnt!=nullptr){
            cnt=cnt->next;
            ns++;
        }

        if(k%ns==0){
            return head;
        }

        for(int i=0;i<k%ns;i++){
            fast=fast->next;
        }

        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;
        fast->next=head;

        return temp;
        
    }
};