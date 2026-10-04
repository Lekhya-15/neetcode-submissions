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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* root=&dummy;
        int carry=0;
        while(l1 || l2){
            int x;
            if(l1 && l2){
                x=(l2->val+l1->val+carry);
                l1->val=x%10;
                carry=x/10;
                root->next=l1;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                x=(l1->val+carry);
                l1->val=x%10;
                carry=x/10;
                root->next=l1;
                l1=l1->next;
            }
            else{
                x=(l2->val+carry);
                l2->val=x%10;
                carry=x/10;
                root->next=l2;
                l2=l2->next;
            }
            root=root->next;
        }

        if(carry) root->next=new ListNode(1);
        return dummy.next;
    }
};
