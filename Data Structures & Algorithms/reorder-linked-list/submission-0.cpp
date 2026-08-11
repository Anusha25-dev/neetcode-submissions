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
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        } //to find the mid
        //reversing the second half of the list
        ListNode* curr=slow->next; //after mid
        ListNode* prev=nullptr;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        slow->next=nullptr; //i.e. last node of (reversed) second half

        ListNode* first=head;
        ListNode* second=prev; //2nd part's head is prev
        while(second){
            ListNode* t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;

            first=t1;
            second=t2;
        }
    }
};
