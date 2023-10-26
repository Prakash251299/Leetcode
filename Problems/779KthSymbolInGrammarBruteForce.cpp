class Solution {
public:
    string opp(string a){
        string s="";
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                s = s+'1';
            }else{
                s = s+'0';
            }
        }
        return s;
    }
    int kthGrammar(int n, int k) {
        string s="0";
        // s = opp(s);
        for(int i=1;i<n;i++){
            s = s + opp(s);
            if(s.size()>k){
                return s[k-1]-'0';
            }
        }
        cout<<s[0];
        // return v[k-1];
        return s[k-1]-'0';
    }
};
