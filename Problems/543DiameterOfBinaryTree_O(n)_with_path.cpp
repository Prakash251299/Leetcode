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
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    } 
    int traverse(TreeNode* q,int &res,TreeNode* &mid){
        if(q==NULL){
            return 0;
        }
        int l=traverse(q->left,res,mid);
        int r=traverse(q->right,res,mid);
        if(l+r+1>res){
            mid=q;
            res=l+r+1;
        }
        return max(l+1,r+1);
    }
    int getEndNode(TreeNode* q,int h,int &mxH,TreeNode* &node){
        if(q==NULL){return 0;}
        if(q->left==NULL&&q->right==NULL){
            if(h>=mxH){
                mxH=h;node=q;
            }
        }
        getEndNode(q->left,h+1,mxH,node);
        getEndNode(q->right,h+1,mxH,node);
        return 0;
    }
    int found=0;
    void getPath(TreeNode* q,TreeNode*&end,vector<int>&path){
        if(q==NULL)return;
        if(q->val==end->val){found=1;path.push_back(q->val);}
        if(found==1){
            return;
        }
        getPath(q->left,end,path);
        if(found==1){
            path.push_back(q->val);
            return;
        }
        getPath(q->right,end,path);
        if(found==1)
        path.push_back(q->val);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        TreeNode* mid;
        traverse(root,res,mid);
        cout<<"mid: "<<mid->val<<endl;
        TreeNode*leftEnd=root;
        TreeNode*rightEnd=root;
        int h=0,mxH=0;
        getEndNode(mid->left,h,mxH,leftEnd);
        h=0,mxH=0;
        getEndNode(mid->right,h,mxH,rightEnd);

        vector<int>leftPath,rightPath;
        getPath(mid->left,leftEnd,leftPath);
        found=0;
        getPath(mid->right,rightEnd,rightPath);
        cout<<"leftEnd:"<<leftEnd->val<<" rightEnd:"<<rightEnd->val<<endl;
        leftPath.push_back(root->val);
        reverse(rightPath.begin(),rightPath.end());
        for(auto x:rightPath){
            leftPath.push_back(x);
        }
        display(leftPath);
        return res-1;
    }
};
