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
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second=dummy;
        //first, move first pointer n+1 steps ahead of second i.e. a gap of n elements in between
        for(int i=0;i<=n;i++){
            first=first->next;
        }
        while(first){
            first=first->next;
            second=second->next;
        }
        //when first reaches nullptr, second will be right before the one to be deleted
        ListNode* del=second->next;
        second->next=second->next->next;
        delete del;
        return dummy->next;
    }
};
