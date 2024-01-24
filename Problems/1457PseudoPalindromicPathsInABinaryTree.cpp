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
    int pallindromable(vector<int>v,int s){
        if(s%2==0){
            for(auto x:v){
                if(x%2!=0){
                    return 0;
                }
            }
        }
        int temp=0;
        if(s%2!=0){
            for(auto x:v){
                if(x%2!=0){
                    ++temp;
                    if(temp>1){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    void traverse(TreeNode* q,vector<int>v,int &count,int s){
        if(q==NULL){
            return;
        }
        ++v[q->val];
        s++;
        if(q->left==NULL and q->right==NULL){
            if(pallindromable(v,s)){
                count++;
            }
        }
        traverse(q->left,v,count,s);
        traverse(q->right,v,count,s);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int>v(10,0);
        cout<<v[9];
        traverse(root,v,count,0);
        return count;
    }
};
