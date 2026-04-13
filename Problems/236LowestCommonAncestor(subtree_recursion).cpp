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
    TreeNode* traverse(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL or root==p or root==q){return root;}
        TreeNode* l = traverse(root->left,p,q);
        TreeNode* r = traverse(root->right,p,q);
        if(l!=NULL&&r!=NULL)return root;
        return l!=NULL?l:r;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root,p,q);
    }
};
