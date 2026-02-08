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
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v;
        vector<int>temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
            if(temp.size()==k){
                for(int i=temp.size()-1;i>=0;i--){
                    v.push_back(temp[i]);
                }
                temp.clear();
            }
        }
        for(auto x:temp){
            v.push_back(x);
        }
        // display(v);
        ListNode *q=new ListNode(0);
        ListNode *r = q;
        for(auto x:v){
            ListNode*temp=new ListNode(x);
            r->next=temp;
            r=r->next;
        }
        return q->next;
    }
};
