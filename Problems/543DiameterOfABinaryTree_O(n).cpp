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
    int traverse(TreeNode* root,int h,int &res){
        if(root==NULL){
            return 0;
        }
        int l=traverse(root->left,h+1,res);
        int r=traverse(root->right,h+1,res);
        if(l+r+1>res){
            res=l+r+1;
        }
        return max(l+1,r+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        traverse(root,0,res);
        return res-1;
    }
};
