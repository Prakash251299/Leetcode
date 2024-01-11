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
    void traverse(TreeNode* q, int max, int min, int &m){
        if(q==NULL){
            return;
        }
        if(q->val<min){
            min = q->val;
        }
        if(q->val>max){
            max = q->val;
        }
        if(max-min>m){
            m = max-min;
        }
        traverse(q->left,max,min,m);
        traverse(q->right,max,min,m);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int m = 0, min = root->val, max = min;
        traverse(root,max,min,m);
        return m;
    }
};
