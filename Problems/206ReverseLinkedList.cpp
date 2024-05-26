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
    void trav(ListNode *q){
        while(q!=NULL){
            cout<<q->val<<" ";
            q = q->next;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev,*curr,*nex;
        if(head==NULL || head->next==NULL){
            return head;
        }
        prev = NULL;
        curr = head;
        nex = head->next;
        // prev->next = NULL;
        curr->next = prev;
        // prev = curr;
        // curr = nex;
        while(1){
            // trav(prev);
            cout<<endl;
            if(nex==NULL){
                curr->next=prev;
                // cout<<curr->next->val;
                // cout<<curr->next->val;
                // head = curr;
                return curr;
            }
            // a = head;
            // b = head->next
            curr->next = prev;
            prev = curr;
            curr = nex;
            nex = nex->next;
        }
    }
};
