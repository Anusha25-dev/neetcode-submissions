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
    struct Compare{ //FOR MIN-HEAP
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq; //REMEMBER FOR MIN-HEAP
        for(ListNode* head:lists){
            if(head!=nullptr)
            pq.push(head);
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* smallest=pq.top();
            pq.pop();
            tail->next=smallest;
            tail=tail->next;
//We need to push the element after the popped element in that particular sublist since only 1 element from each sublist is pushed intp pq (initially just the heads)
            if(smallest->next!=nullptr){
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};
