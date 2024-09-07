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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int t=0;
    void check(ListNode* h, TreeNode* r){
        if(h==NULL){
            t=1;
            return;
        }
        if(r==NULL){
            return;
        }
        if(h->val!=r->val){
            return;
        }
        cout<<r->val<<" ";
        if(t==0){
            check(h->next,r->left);
        }
        if(t==0){
            check(h->next,r->right);
        }
        return;
    }

    void traverse(ListNode* h, TreeNode* r){
        if(r==NULL){
            return;
        }
        if(h->val==r->val){
            // cout<<r->val<<" ";
            if(t==0)
            check(h,r);
        }
        if(t==0)
        traverse(h,r->left);
        if(t==0)
        traverse(h,r->right);
        return;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        traverse(head,root);
        return t;
    }
};
