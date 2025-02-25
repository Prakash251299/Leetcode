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
    int found=0;
    string s = "";
    void traverse(TreeNode* q,char t,int a){
        if(q==NULL){
            return;
        }
        if(q->val==a){
            found=1;s+=t;
            return;
        }
        traverse(q->left,'L',a);
        if(found==0){
            traverse(q->right,'R',a);
        }
        if(found==1){
            s+=t;
        }
        return;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        found = 0;
        traverse(root,'\0',destValue);
        reverse(s.begin(),s.end());
        string s1 = s;
        s = "";
        found=0;
        traverse(root,'\0',startValue);
        reverse(s.begin(),s.end());
        int i=0;
        for(i=0;i<s.size() && i<s1.size();i++){
            if(s[i]!=s1[i]){
                break;
            }
        }
        string res;
        for(int j=i;j<s.size();j++){
            res+='U';
        }
        for(int j=i;j<s1.size();j++){
            res+=s1[j];
        }
        return res;
    }
};
