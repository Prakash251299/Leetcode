class Solution {
public:
    void display(unordered_map<string,int>m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        return;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>m;
        vector<string>v;
        string t = "";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                ++m[t];
                t="";
            }else{
                t+=s1[i];
            }
            if(i+1==s1.size()){
                ++m[t];
            }
        }
        t="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                ++m[t];
                t="";
            }else{
                t+=s2[i];
            }
            if(i+1==s2.size()){
                ++m[t];
            }
        }
        // display(m);
        for(auto x:m){
            if(x.second==1){
                v.push_back(x.first);
            }
            // cout<<x.first<<":"<<x.second<<"\n";
        }
        return v;
    }
};
