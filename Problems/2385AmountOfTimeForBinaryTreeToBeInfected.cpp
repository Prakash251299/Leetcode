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
    // void infect(unordered_map<int,vector<int>>m,int h,int prev,int x){
    //     // cout<<h<<" ";
    //     if(h>max){
    //         max = h;
    //     }
    //     if(m[x].size()>1){
    //         for(auto y:m[x]){
    //             if(y!=prev){
    //                 infect(m,h+1,x,y);
    //             }
    //             if(y==prev){
    //                 continue;
    //             }
    //         }
    //     }
    //     // if(){
            
    //     // }
    //     return;
    // }

    int amountOfTime(TreeNode* root, int start) {
        int f=0,h=0,prev = start;
        unordered_map<int,vector<int>>m;
        traverse(root,m);
        // for(auto x:m){
        //     cout<<x.first<<":";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }

        // cout<<m[start].size();
        // cout<<m[start];








        queue<int> q;
        q.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int current = q.front();
                q.pop();

                for (int num : m[current]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;














        // queue<int>q;
        // unordered_set<int>visited;
        // q.push(start);
        // int min = -1;
        // while(!q.empty()){
        //     min++;
        //     int n = q.size();
        //     while(n--){
        //         int curr = q.front();
        //         q.pop();
        //         for(int &ng:m[curr]){
        //             if(visited.find(ng)==visited.end()){
        //                 q.push(ng);
        //                 visited.insert(ng);
        //             }
        //         }
        //     }
        //     min++;
        // }
        // return min-1;


        // for(auto x:m[start]){
        //     infect(m,h+1,prev,x);
        //     // cout<<x<<" ";
        // }
        // return max;
    }
};
