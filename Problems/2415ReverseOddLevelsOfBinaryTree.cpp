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
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    void reverse(vector<int>&v,int i,int j){
        // cout<<i<<","<<j<<"\n";
        for(;i<j;){
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;j--;
        }
        return;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* r;
        int i=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            // cout<<q.front()->val<<" ";
            v.push_back(q.front()->val);
            q.pop();
        }
        // display(v);
        for(int i=1;pow(2,i)<v.size();i+=2){
            int a = pow(2,i)-1;
            reverse(v,a,a+a);
        }
        // display(v);


        q.push(root);
        i=1;
        while(!q.empty()){
            if(q.front()->left!=NULL){
                q.front()->left->val = v[i];
                q.push(q.front()->left);
                i++;
            }
            if(q.front()->right!=NULL){
                q.front()->right->val = v[i];
                q.push(q.front()->right);
                i++;
            }
            q.pop();
        }
        // return r;
        return root;
    }
};
