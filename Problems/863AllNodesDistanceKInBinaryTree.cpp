/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void display(map<int,TreeNode*>&m){
        for(auto x:m){
            // if(x.second!=NULL)
            cout<<x.first<<":"<<x.second->val<<"\n";
        }
        cout<<"\n";
        return;
    }
    void findParent(TreeNode* root,map<int,TreeNode*>&m){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            m[root->left->val] = root;
        }
        if(root->right!=NULL){
            m[root->right->val] = root;
        }
        findParent(root->left,m);
        findParent(root->right,m);
        return;
    }
    void find_k_distant_nodes(TreeNode* target,vector<int>&v,int &k,map<int,TreeNode*>&parent){
        // cout<<"target"<<target<<"\n";
        queue<TreeNode*>q;
        map<TreeNode*,int>visited;
        q.push(target);
        visited[target]=1;
        int h=0,flag=0;
        while(!q.empty() && h<=k){
            int sz = q.size();
            // if(flag==1){
            //     break;
            // }
            for(int i=0;i<sz;i++){
                // cout<<"\nQueue size: "<<q.size()<<"\n";
                // cout<<q.front()->val<<":";
                if(h==k){
                    if(q.front()!=NULL)
                    v.push_back(q.front()->val);
                    // q.pop();

                    // flag=1;
                    // break;
                }else{
                    if(parent[q.front()->val]!=q.front() && visited[parent[q.front()->val]]!=1){
                        q.push(parent[q.front()->val]);
                        visited[parent[q.front()->val]]=1;
                        // cout<<"Parent:"<<parent[q.front()->val]<<"\n";
                    }
                    if(q.front()->left!=NULL && visited[q.front()->left]!=1){
                        q.push(q.front()->left);
                        visited[q.front()->left]=1;
                        // cout<<"Left:"<<q.front()->left->val<<"\n";
                    }
                    if(q.front()->right!=NULL && visited[q.front()->right]!=1){
                        q.push(q.front()->right);
                        visited[q.front()->right]=1;
                        // cout<<"Right:"<<q.front()->right->val<<"\n";
                    }
                }
                q.pop();
            }
            h++;
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        map<int,TreeNode*>parent;
        vector<int>v;
        parent[root->val]=root;
        findParent(root,parent);
        // display(parent);
        // if(target!=NULL)
        // cout<<target->left->val;
        find_k_distant_nodes(target,v,k,parent);
        return v;
    }
};
