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
    int max=10000;
    int traverseFun(TreeNode* root,int count){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL and root->right==NULL){
            if(max>count){
                max = count+1;
            }
        }
        traverseFun(root->left,count+1);
        traverseFun(root->right,count+1);
        return 0;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        traverseFun(root,count);
        cout<<max;
        return max;
    }
};
