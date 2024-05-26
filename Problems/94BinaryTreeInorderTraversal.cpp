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
    void fun(vector<int>&v,TreeNode* q){
        if(q==NULL){
            return;
        }
        fun(v,q->left);
        v.push_back(q->val);
        fun(v,q->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        fun(v,root);
        return v;
    }
};
