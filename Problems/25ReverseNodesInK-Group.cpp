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
    ListNode* g=NULL;
    int n=1;
    void traverse(ListNode* q,vector<int>&v,int k,int i,int s){
        if(q==NULL){
            g = NULL;
            return;
        }
        if(i>=k){
            g = q; // for keeping track till where we have reached
            return;
        }
        traverse(q->next,v,k,i+1,s);
        if(n<=k*s){ // for pushing only till required node because after this(k*c), no reversal required
            v.push_back(q->val);
        }
        n++;
        return;
    }

    int getSizeOfLinkedList(ListNode* q){
        int s=0;
        while(q!=NULL){
            s++;
            q = q->next;
        }
        return s;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* q=head;
        vector<int>v;
        int s = getSizeOfLinkedList(head);
        s=s/k; // it helps in knowing that after how many elements we have to stop reversing by the formula s*k 
        while(q!=NULL){
            traverse(q,v,k,0,s);
            q = g;
            // c++;
        }
        int c=1;
        q = head;
        // Now pushing the remaining node data which should not be reversed
        while(q!=NULL){
            if(c>s*k){
                v.push_back(q->val);
            }
            c++;
            q = q->next;
        }
        q=head;
        int i=0;
        // copying all data from vector to linkedlist
        while(q!=NULL){
            q->val=v[i];
            q=q->next;
            i++;
        }
        return head;
    }
};
