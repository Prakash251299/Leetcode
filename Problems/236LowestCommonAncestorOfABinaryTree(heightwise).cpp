/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode*root,int h,TreeNode* p,TreeNode* q,int &f1,int &f2,int &low,TreeNode*&anc){
        if(root==NULL)return;
        if(f1==1&&f2==1){
            return;
        }
        // cout<<"h"<<h<<endl;
        if(root->val==p->val){
            f1=1;
            if(low==INT_MAX){
                low=h;
                anc=root;
            }
        }
        if(root->val==q->val){
            f2=1;
            if(low==INT_MAX){
                low=h;
                anc=root;
            }
        }
        if(root->left!=NULL){
            traverse(root->left,h+1,p,q,f1,f2,low,anc);
        }
        if(f1==1&&f2==1){}else
        if(f1==1||f2==1){
            if(h<low){
                low=h;
                anc=root;
            }
            // cout<<"ancestor: "<<anc->val<<" h: "<<h<<" low: "<<low<<endl;
        }
        if(root->right!=NULL){
            traverse(root->right,h+1,p,q,f1,f2,low,anc);
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int f1=0,f2=0,low=INT_MAX;
        TreeNode* anc=p;
        traverse(root,0,p,q,f1,f2,low,anc);
        return anc;
    }
};
