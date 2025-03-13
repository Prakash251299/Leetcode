/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<string>
class Codec {
public:
    void fun(TreeNode* q,string &s){
        if(q==NULL){
            return;
        }
        s+="L";
        if(q->left!=NULL){
            // s+="L";
            s+=to_string(q->left->val);
            fun(q->left,s);
        }else{
            s+="n";
        }
        s+="R";
        if(q->right!=NULL){
            s+=to_string(q->right->val);
            fun(q->right,s);
        }else{
            s+="n";
        }
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL){
            return "";
        }
        s+=to_string(root->val);
        fun(root,s);
        return s;
    }


    int getInt(string &data, int &i, string &s){
        while(int(data[i])-'0'>=0 && int(data[i])-'0'<=9){
            s.push_back(data[i]);
            i++;
        }
        return stoi(s);
    }

    void traverse(TreeNode* q, string &s, int &i){
        if(i>=s.size() || q==NULL){
            return;
        }
        if(s[i]=='L'){
            i++;
            if(s[i]=='n'){
                q->left = NULL;
                i++;
                traverse(q,s,i);
                return;
            }else{
                string s1="";
                int t=0;
                s1.push_back(s[i]);
                i++;
                t = getInt(s,i,s1);
                TreeNode* newNode = new TreeNode(t);
                q->left = newNode;
                traverse(q->left,s,i);
                traverse(q,s,i);
                return;
            }
        }else
        if(s[i]=='R'){
            i++;
            if(s[i]=='n'){
                q->right = NULL;
                i++;
                return;
            }else{
                string s1="";
                int t=0;
                s1.push_back(s[i]);
                i++;
                t = getInt(s,i,s1);
                TreeNode* newNode = new TreeNode(t);
                q->right = newNode;
                traverse(q->right,s,i);
                return;
            }
        }
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<"mystring: "<<data<<"\n";
        if(data.size()==0){
            return NULL;
        }
        int i=0;
        string s="";
        int t=0;
        s.push_back(data[i]);
        i++;
        t = getInt(data,i,s);
        TreeNode* q = new TreeNode(t);
        if(data.size()==1){
            return q;
        }
        traverse(q,data,i);
        return q;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
