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
    int maxh=0;
    void traverse(TreeNode* root,int n,unordered_map<int,vector<int>>&m){
        if(root==NULL){
            return;
        }
        traverse(root->left,n+1,m);
        m[n].push_back(root->val);
        if(n>maxh){
            maxh=n;
        }
        traverse(root->right,n+1,m);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int,vector<int>>m;
        vector<vector<int>>v;
    /* DFS done and stored every element in the map with its level no. as vectors */
        traverse(root,1,m);
        /* Vectors are now fetched and stored in a 2d vector for bfs */
        for(int i=0;i<maxh;i++){
            v.push_back(m[i+1]);
        }
        return v;
    }
};
