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
    void traverse(TreeNode* q, unordered_map<int,vector<int>>&m){
        if(q==NULL){
            return;
        }
        if(q->left!=NULL){
            m[q->val].push_back(q->left->val);
            m[q->left->val].push_back(q->val);
        }
        if(q->right!=NULL){
            m[q->val].push_back(q->right->val);
            m[q->right->val].push_back(q->val);
        }
        traverse(q->left,m);
        traverse(q->right,m);
        return;
    }

    int max=0;

    void infected(unordered_map<int,vector<int>>m,unordered_set<int>&visited,int start){
        queue<int>q;
        q.push(start);
        visited.insert(start);
        int minute=0;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                int curr = q.front();
                q.pop();
                for(auto x:m[curr]){
                    if(visited.find(x)==visited.end()){
                        q.push(x);
                        visited.insert(x);
                    }
                }
                size--;
            }
            minute++;
        }
        max = minute-1;
        return;
    }

    int amountOfTime(TreeNode* root, int start) {
        int f=0,h=0,prev = start;
        unordered_map<int,vector<int>>m;
        traverse(root,m);
        unordered_set<int>visited;
        infected(m,visited,start);
        return max;
    }
};
