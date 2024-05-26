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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* q;
        ListNode* res;
        if(list1->val<=list2->val){
            q=list1;
            list1 = list1->next;
        }else{
            q=list2;
            list2 = list2->next;
        }
        res = q;
        while(1){
            if(list1==NULL){
                q->next = list2;
                break;
            }
            if(list2==NULL){
                q->next = list1;
                break;
            }
            if(list1->val <= list2->val){
                q->next = list1;
                list1 = list1->next;
            }else{
                q->next = list2;
                list2 = list2->next;
            }
            q = q->next;
        }
        return res;
    }
};