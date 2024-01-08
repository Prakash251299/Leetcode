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
    void add(TreeNode* q, int low, int high, int& sum){
        // int a=sum;
        if(q==NULL){
            return;
        }
        if(q->val>=low and q->val<=high){
            sum += q->val;
        }
        if(q->val>=low){
            add(q->left,low,high,sum);
        }
        if(q->val<=high){
            add(q->right,low,high,sum);
        }
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        add(root,low,high,sum);
        return sum;
    }
};
