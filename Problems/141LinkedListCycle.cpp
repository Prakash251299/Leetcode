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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode *slow,*fast;
        slow = head;
        fast = head->next;
        while(true){
            if(fast==NULL){
                return false;
            }
            if(slow==fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast==NULL){
                return false;
            }else{
                fast = fast->next;
            }
        }
        return true;
    }
};
