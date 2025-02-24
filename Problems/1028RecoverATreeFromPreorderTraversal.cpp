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
    int countDash(string &s,int i){
        int c=0,j=0;
        for(j = i+1;j<s.size();j++){
            if(s[j]=='-'){
                c++;
            }else{
                break;
            }
        }
        return c;
    }

    int getInt(string &s, int i,int &len){
        string num = "";
        int c = 0;
        for(i=i+1;i<s.size();i++){
            int t = int(s[i])-int('0');
            if(t<10 && t>=0){
                num+=s[i];
                c++;
            }else{
                break;
            }
        }
        len = c;
        return stoi(num);
    }

    void callFun(string &s, TreeNode* &root, int &i, int curr,TreeNode* &prev){
        if(i+1>=s.size()){
            return;
        }
        int next = countDash(s,i);
        if(curr<next){
            i+=next;
            int len=0;
            int num = getInt(s,i,len);
            TreeNode* newNode = new TreeNode(num);
            root = newNode;
            i+=len;
            callFun(s,root->left,i,next,root);
            next = countDash(s,i);
            if(curr>=next){
                return;
            }
            i+=next;
            len = 0;
            num = getInt(s,i,len);
            newNode = new TreeNode(num);
            prev->right = newNode;
            i+=len;
            callFun(s,prev->right->left,i,next,prev->right);
        }
        return;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int len=0,i=-1;
        int num = getInt(traversal,-1,len);
        TreeNode* root = new TreeNode(num);
        i+=len;
        int curr=0,next=0;
        callFun(traversal,root->left,i,0,root);
        if(i+1<traversal.size()){
            callFun(traversal,root->right,i,next,root);
        }
        return root;
    }
};
