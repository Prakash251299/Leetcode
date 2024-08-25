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
    void traverse(TreeNode* q, vector<int>&v){
        if(q==NULL){
            return;
        }
        traverse(q->left,v);
        traverse(q->right,v);
        v.push_back(q->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        traverse(root,v);
        return v;
    }
};
