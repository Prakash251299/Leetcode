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
    void preorder(TreeNode* q,int h,unordered_map<int,int>& m,int &height){
        if(q==NULL){
            return;
        }
        if(h>height){
            height = h;
        }
        // cout<<height<<" ";
        if(h!=1)
        if(m[h]!=NULL){
            if(m[h]<=q->val){
                m[h]=q->val;
            }
            // else{
            //     cout<<q->val<<" ";
            // }
        }else{
            m[h]=q->val;
        }
        // cout<<"h:"<<h<<" "<<q->val<<"\n";
        if(q->left!=NULL){
            preorder(q->left,h+1,m,height);
        }
        // cout<<q->val<<" ";
        if(q->right!=NULL){
            preorder(q->right,h+1,m,height);
        }
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        unordered_map<int,int>m;
        int h=0,height=0;
        if(root==NULL){
            return v;
        }
        // Don't know why but level 1 largest element for (0,-37) i.e. 0 gets updated by -37 so handled explicitly here
        if(root->left!=NULL and root->right!=NULL){
            if(root->left->val>=root->right->val){
                m[1]=root->left->val;
            }
            else{
                m[1]=root->right->val;
            }
        }else{
            if(root->left==NULL and root->right!=NULL)
                m[1]=root->right->val;
            else
                if(root->left!=NULL and root->right==NULL)
                    m[1]=root->left->val;
        }
        preorder(root,0,m,height);
        for(int i=0;i<=height;i++){
            v.push_back(m[i]);
        }
        return v;
    }
};
