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
    int val = pow(10,9)+5;
    void fun(TreeNode* root, TreeNode* p, TreeNode* q, int &l,int &r, TreeNode* &min,int h,int &minH){
        if(l==1&&r==1){
            // min = root;
            return;
        }
        if(root==NULL){
            return;
        }
        // cout<<root->val<<": "<<p->val<<" "<<q->val<<"\n";
        if(root->val==p->val){
            // cout<<"h\n";
            l=1;
        }
        if(root->val==q->val){
            // cout<<"i\n";
            r=1;
        }
        if(h<minH && ((l==0&&r==1)||(l==1&&r==0))){
            min = root;
            minH=h;
            // cout<<"j:"<<min->val<<"\n";
            // cout<<min->val;
        }
        // if(l==1&&r==1){return;}
        fun(root->left,p,q,l,r,min,h+1,minH);
        if((l==0&&r==1)||(l==1&&r==0)){
            if(h<minH){
                min = root;
                minH=h;
                // cout<<"k:"<<min->val<<"\n";
            }
        }
        fun(root->right,p,q,l,r,min,h+1,minH);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* min = new TreeNode(val);
        int l=0,r=0,h=0,minH=INT_MAX;
        fun(root,p,q,l,r,min,h,minH);
        return min;
    }
};
