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

        ListNode* current = new ListNode(0); // it makes a node with 0 value
        ListNode* temp=current; // head of the list whose next is to be returned

        while (head != NULL) {
            if (!m[head->val]) {
                current->next = head;
                current = current->next;
            }
            head = head->next;
        }
        current->next = NULL;

        return temp->next;
    }
};
