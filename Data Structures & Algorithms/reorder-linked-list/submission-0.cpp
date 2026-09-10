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
    void reorderList(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;

        while(fast!= nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* curr=slow->next;
        slow->next = nullptr;
        ListNode* prev=nullptr;

        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        while(prev!=nullptr){
            curr=head->next;
            fast=prev->next;
            head->next=prev;
            prev->next=curr;
            head=curr;
            prev=fast;
        }

        return;
    }
};
