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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *q = head, *r=head;
        int i=0;
        for(i=0;;i++){
            if(q==NULL){
                break;
            }
            // cout<<q->val;
            q = q->next;
        }
        if(k>i/2){
            k = i-k+1;
        }
        q = head;
        // ListNode *r=head;
        int j=1,l=0;
        while(1){
            if(l==i-k){
                break;
            }
            if(j!=k){
                j++;
                q=q->next;
            }
            if(l!=i-k){
                l++;
                r = r->next;
                // break;
            }
            
        }
        int temp = q->val;
        q->val = r->val;
        r->val = temp;
        
        cout<<q->val<<" "<<r->val;
        return head;
    }
};