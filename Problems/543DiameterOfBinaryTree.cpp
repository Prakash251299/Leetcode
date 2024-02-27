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
    int max=0;
    int fun(TreeNode* q){
        if(q==NULL){
            return 0;
        }
        // int t=a;
        int b = fun(q->left);
        int c = fun(q->right);
        if(b+c>max){
            max = b+c;
        }
        // cout<<a<<" ";
        if(b>=c){
            return b+1;
        }
        return c+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a=0;
        a = fun(root);
        return max;
    }
};
