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
    int traverse(TreeNode* q, int &mx){
        if(q->left==NULL && q->right==NULL){
            mx=max(q->val,mx);
            return q->val;
        }
        int l=0,r=0;
        if(q->left!=NULL){
            l=traverse(q->left,mx);
            mx=max(l,max(mx,q->val+l));
        }
        if(q->right!=NULL){
            r=traverse(q->right,mx);
            mx=max(r,max(mx,q->val+r));
        }
        mx = max(mx,l+r+q->val);
        if(l>=r){
            if(l<0){
                return q->val;
            }
            return l+q->val;
        }
        else{
            if(r<0){
                return q->val;
            }
            return r+q->val;
        }
        return q->val;
    }

    int maxPathSum(TreeNode* root) {
        int mx=root->val;
        traverse(root,mx);
        return mx;
    }
};
