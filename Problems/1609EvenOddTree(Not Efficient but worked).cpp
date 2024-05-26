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
    /* map will contain current level's previous data, to which 
    current node value is compared for checking the increasing
    decreasing order in the respective level as required */
    unordered_map<int,int>m;
    /* r contains the result whether the conditions are anywhere
    being voilated, if so then that r is returned without 
    further operation */
    bool r = true;
    void dfs(TreeNode*q,int h){
        if(q==NULL || r==false){
            return;
        }

        /* if the current node is not the start of the level */

        // if(m.find(h)!=m.end()){
        if(m[h]!=0){
            if(h%2==0){
                if(q->val%2==0){
                    r = false;
                    return;
                }
                if(m[h]>=q->val){
                    r = false;
                    return;
                }else{
                    // cout<<h<<": "<<m[h]<<" "<<q->val<<"\n";
                    m[h] = q->val;
                }
            }else{
                if(q->val%2!=0){
                    r = false;
                    return;
                }
                if(m[h]<=q->val){
                    r = false;
                    return;
                }else{
                    // cout<<h<<": "<<m[h]<<" "<<q->val<<"\n";
                    m[h] = q->val;
                }
            }
        }else{
        /* if the current node is the start node of that level */
            if(h%2==0){
                if(q->val%2==0){
                    r = false;
                    return;
                }
            }else{
                if(q->val%2!=0){
                    r = false;
                    return;
                }
            }
            /* Map will contain current node value as it the only
            node in the level right now */
            m[h] = q->val;
        }
        if(r==true)
        dfs(q->left,h+1);
        if(r==true)
        dfs(q->right,h+1);
        return;
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root,0);
        return r;
    }
};
