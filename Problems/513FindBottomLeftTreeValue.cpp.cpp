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
    int max=0,res=0;
    void fun(TreeNode* q,int h){
        if(q==NULL){
            return;
        }
        fun(q->left,h+1);
        if(h>max){
            max=h;
            res = q->val;
        }
        fun(q->right,h+1);
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        if(root->left==NULL and root->right==NULL){
            return root->val;
        }
        fun(root,0);
        return res;
    }
};
