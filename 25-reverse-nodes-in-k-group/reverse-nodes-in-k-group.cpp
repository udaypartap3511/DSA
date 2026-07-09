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
    ListNode* kthNode(ListNode* temp,int k){
        k--;
        while(temp!=nullptr && k--){
            temp=temp->next;
        }

        return temp;
    }
    ListNode* reverseLinkList(ListNode* temp){
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* Next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=Next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode= kthNode(temp,k);
            if(kthnode==nullptr){
                if(prevNode!=nullptr) prevNode->next=temp;
                break;
            }


            ListNode* nextNode=kthnode->next;
            kthnode->next=nullptr;
            reverseLinkList(temp);

            if(temp==head){
                head=kthnode;
            }
            else{
                prevNode->next=kthnode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        
        return head;
        
    }
};