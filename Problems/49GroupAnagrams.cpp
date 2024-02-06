class Solution {
public:
    void count_map(string s, vector<unordered_map<int,int>>&v){
        unordered_map<int,int>m;
        for(int i=0;i<s.size();i++){
            ++m[s[i]];
        }
        v.push_back(m);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>v;
        vector<string>v1;
        vector<unordered_map<int,int>>vm;
        vector<int>check(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            count_map(strs[i],vm);
        }
        for(int i=0;i<strs.size();i++){
            if(check[i]==0){
                v1.push_back(strs[i]);
                check[i]=1;
                for(int j=i+1;j<strs.size();j++){
                    if(check[j]==0){
                        if(vm[i] == vm[j]){
                            v1.push_back(strs[j]);
                            check[j]=1;
                        }
                    }
                }
                v.push_back(v1);
            }
            v1.clear();
        }
        return v;
    }
};
