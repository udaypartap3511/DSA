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

        unordered_map<ListNode*,ListNode*> mp;

        ListNode* l1=headA;
        while(l1!=nullptr){
            mp[l1]=l1->next;
            l1=l1->next;
        }
        
        ListNode* l2=headB;
        while(l2!=nullptr){
            if(mp.find(l2)!=mp.end()){
                return l2;
            }
            l2=l2->next;
        }
        return nullptr;
    }
};