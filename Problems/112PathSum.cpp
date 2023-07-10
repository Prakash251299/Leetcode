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
class Solution{
public:
    bool v = false;
    void traverse(TreeNode* root, int targetSum, int sum){
        if(root==NULL){
            return;
        }
        sum = sum + root->val;
        if(sum==targetSum){
            if(root->left==NULL and root->right==NULL){
                v = true;
            }
        }
        traverse(root->left,targetSum,sum);
        traverse(root->right,targetSum,sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        traverse(root,targetSum,0);
        return v;
    }
};