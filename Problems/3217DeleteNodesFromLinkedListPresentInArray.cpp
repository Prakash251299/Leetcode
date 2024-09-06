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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res=NULL;
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x] = 1;
        }
        if(m[head->val]!=1){
            res = head;
        }

        while(1){
            if(head==NULL){
                break;
            }
            if(head->next==NULL){
                break;
            }
            if(m[head->next->val]!=1 && res==NULL){
                res = head->next;
            }
            if(m[head->next->val]==1){
                head->next = head->next->next;
                continue;
            }
            head=head->next;

        }
        return res;
    }
};
