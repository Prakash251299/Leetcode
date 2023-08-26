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
    int gcd(int a,int b){
    int i=0;
        if(a<b){
            i=a;
            for(;i>0;i--){
                if(b%i==0 && a%i==0){
                    break;
                }
            }
            return i;
        }else{
            i=b;
            for(;i>0;i--){
                if(b%i==0 && a%i==0){
                    break;
                }
            }
            return i;
        }
    }
    
    int builtInGcdFinder(int a, int b){
        return __gcd(a,b);
    }
    
    void fun(ListNode* q){
        if(q==NULL){
            return;
        }
        if(q->next==NULL){
            return;
        }
        ListNode *r = new ListNode();
        int g = builtInGcdFinder(q->val,q->next->val);
        // ListNode *r;
        // ListNode *r=(struct ListNode*)malloc(sizeof(struct ListNode));
        r->val=g;
        r->next = q->next;
        q->next = r;
        fun(r->next);
        return;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        fun(head);
        // ListNode* q=new ListNode();
        // q = head;
        // q=q->next;
        // q->val = 5;
        // cout<<q->val;
        // cout<<head->next->val;
        return head;
    }
};