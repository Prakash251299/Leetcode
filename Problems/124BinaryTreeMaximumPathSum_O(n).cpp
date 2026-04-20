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
    int traverse(TreeNode*q, int &res){
        if(q==NULL){
            return 0;
        }
        int l=traverse(q->left,res);
        int r=traverse(q->right,res);
        int mx=max(l+q->val,max(r+q->val,q->val));
        res=max(res,max(l+q->val,max(r+q->val,max(q->val,l+r+q->val))));
        return mx;
    }
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        traverse(root,res);
        return res;
    }
};
