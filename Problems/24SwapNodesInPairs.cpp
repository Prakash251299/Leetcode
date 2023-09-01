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
    void swap(ListNode* head){
        if(head==NULL || head->next==NULL){
            return;
        }
        int a=0;
        a=head->val;
        head->val = head->next->val;
        head->next->val = a;
        swap(head->next->next);
        return;
    }
    
    ListNode* swapPairs(ListNode* head) {
        swap(head);
        return head;
    }
};