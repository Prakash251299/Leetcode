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
    void leafFinder(TreeNode* q,vector<int>&v){
        if(q==NULL){
            return;
        }
        if(q->left==NULL and q->right==NULL){
            v.push_back(q->val);
        }
        leafFinder(q->left,v);
        leafFinder(q->right,v);
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        leafFinder(root1,v1);
        leafFinder(root2,v2);
        if(v1==v2){
            return true;
        }
        return false;
    }
};
