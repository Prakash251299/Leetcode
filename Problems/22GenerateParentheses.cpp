class Solution {
public:
    void display(set<string>s){
        for(auto x:s){
            cout<<x<<" ";
        }
        return;
    }

    void traverse(string str, set<string>&s, int n ){
        if(str.size()/2==n){
            // cout<<str<<" ";
            s.insert(str);
            return;
        }
        string t = str;
        for(int i=0;i<str.size();i++){
            t.insert(i,"()");
            traverse(t,s,n);
            t = str;
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        string t = "()";
        set<string>s;
        // if(n==1){
        //     return {"()"};
        // }
        vector<string>res;
        traverse(t,s,n);
        // cout<<s.size()<<"\n";
        for(auto x:s){
            res.push_back(x);
        }
        return res;
    }
};
