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
    void traverse(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        traverse(root->left,v);
        v.push_back(root->val);
        traverse(root->right,v);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        unordered_map<int,int>m;
        /* Traverse the tree and store the elements in a vector in sorted order */
        traverse(root,v);
        for(int i=0;i<v.size();i++){
            m[v[i]]=++m[v[i]];
        }
        int max=0;
        /* Check for the max repeatition of any element */
        for(auto x:m){
            if(x.second>=max){
                max=x.second;
            }
        }
        v.clear();
        /* Store each element in 'v' with maximum repeatition which will be the mode */
        for(auto x:m){
            if(x.second==max){
                v.push_back(x.first);
            }
        }
        return v;
    }
};
