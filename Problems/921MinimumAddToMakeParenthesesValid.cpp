class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0;
        vector<char>v;
        for(auto x:s){
            if(v.size()>0){
                if(x==')' && v[v.size()-1]=='('){
                    v.pop_back();
                    continue;
                }
            }
            v.push_back(x);
        }
        return v.size();
    }
};
