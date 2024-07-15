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
        map<int,int>m;
        int rootVal = 0;
        map<int,map<int,int>>t;
        
        /* Finding root */
        for(auto x:descriptions){
            m[x[1]]=1;
        }
        // for(auto x:m){
        //     cout<<x.first<<":"<<x.second<<"\n";
        // }
        for(auto x:descriptions){
            if(m[x[0]]==0){
                rootVal = x[0];
            }
        }
        // cout<<rootVal<<endl;

        /* String left and right nodes of each node */
        for(auto x:descriptions){
            t[x[0]][x[2]]=x[1];
        }

        TreeNode* res = new TreeNode(rootVal);
        TreeNode* root = res;
        queue<TreeNode*>q;
        q.push(root);

        /* Adding nodes to form a binary tree */
        for(;!q.empty();){
            // cout<<q.front();
            res=q.front();
            if(t[q.front()->val][1]!=0){
                TreeNode* temp = new TreeNode(t[q.front()->val][1]);
                res->left=temp;
                // cout<<root->left->val;
                // return root;
                q.push(temp);
            }
            if(t[q.front()->val][0]!=0){
                TreeNode* temp = new TreeNode(t[q.front()->val][0]);
                res->right=temp;
                q.push(temp);
            }
            q.pop();
        }
        return root;
    }
};
