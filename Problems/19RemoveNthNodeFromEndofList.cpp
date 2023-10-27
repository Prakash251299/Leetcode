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
    int listSize(ListNode* q){
        int s=0;
        while(q!=NULL){
            s++;
            q = q->next;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = listSize(head);
        ListNode* q=head;
        if(n==l){
            head = head->next;
            return head;
        }
        for(int i=0;i<l-n-1;i++){
            q = q->next;
        }
        q->next = q->next->next;
        // cout<<l;
        return head;
    }
};
