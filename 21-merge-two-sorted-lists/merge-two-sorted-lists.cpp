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
        
        ListNode* h1=list1;
        ListNode* h2=list2;
        ListNode* curr=nullptr;
        ListNode* prev=nullptr;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val<=h2->val){
                curr=h1;
                h1=h1->next;
                curr->next=prev;
                prev=curr;
            }
            else{
               curr=h2;
               h2=h2->next;
                curr->next=prev;
                prev=curr;
            }
        }

        while(h1!=nullptr){
            curr=h1;
            h1=h1->next;
            curr->next=prev;
            prev=curr;
        }
        while(h2!=nullptr){
            curr=h2;
            h2=h2->next;
            curr->next=prev;
            prev=curr;
        }

        ListNode* now= prev;
        ListNode* prevnow=nullptr;

        while(now!=nullptr){
            ListNode* next=now->next;
            now->next=prevnow;
            prevnow=now;
            now=next;
        }

        return prevnow;

    }
};