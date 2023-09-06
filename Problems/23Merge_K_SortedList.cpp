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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        int flag=0;
        /* For managing lists with all null datas {if a single data is present in the lists flag becomes 1} */
        for(int i=0;i<lists.size();i++){ 
            if(lists[i]!=NULL){
                flag=1;
            }
        }
        if(flag==0){
            return NULL;
        }
        int i=0,j=0;
        ListNode* q;
        vector<int>v;
        /* Storing all lists datas in a vector */
        for(i=0;i<lists.size();i++){
            q = lists[i];
            while(q!=NULL){
                v.push_back(q->val);
                q=q->next;
            }
        }
        sort(v.begin(),v.end());
        /* r is a linkedlist that will store sorted vector 'v' */
        ListNode* r = new ListNode();
        q = r; // q will be the head for r
        for(i=0;i<v.size();i++){
            r->val=v[i];
            if(i+1<v.size()){
                r->next = new ListNode();
            }
            r = r->next;
        }
        return q; // q is head of r that is to be returned
    }
};