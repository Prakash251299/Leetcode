class Solution {
public:
    void display(vector<char>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    int minLength(string s) {
        vector<char>v;
        for(int i=0;i<s.size();i++){
            if(v.size()>0){
                if((s[i]=='B' && v[v.size()-1]=='A')||(s[i]=='D' && v[v.size()-1]=='C')){
                    v.pop_back();
                    continue;
                }
            }
            v.push_back(s[i]);
        }
        return v.size();
    }
};
