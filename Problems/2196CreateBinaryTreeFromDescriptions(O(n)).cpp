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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<TreeNode*>m(100001,NULL);
        unordered_map<int,int>child;
        int i=0;
        while(i<descriptions.size()){
            child[descriptions[i][1]]=1;
            TreeNode *q;
            if(m[descriptions[i][0]]!=NULL){
                q=m[descriptions[i][0]];
            }else{
                q=new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]]=q;
            }
            if(m[descriptions[i][1]]!=NULL){
                if(descriptions[i][2]==1){
                    q->left=m[descriptions[i][1]];
                }else{
                    q->right=m[descriptions[i][1]];
                }
            }else{
                TreeNode *r=new TreeNode(descriptions[i][1]);
                if(descriptions[i][2]==1){
                    q->left=r;
                }else{
                    q->right=r;
                }
                m[descriptions[i][1]]=r;
            }
            i++;
        }
        for(auto x:descriptions){
            if(child[x[0]]==0){
                return m[x[0]];
            }
        }
        return NULL;
    }
};
