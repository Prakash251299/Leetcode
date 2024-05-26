class Solution {
public:
    void disvec(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        return;
    }
    string frequencySort(string s) {
        vector<int>v(128,0);
        unordered_map<int,vector<char>>m;
        for(int i=0;i<s.size();i++){
            ++v[s[i]];
        }
        for(int i=0;i<128;i++){
            if(v[i]>0)
                m[v[i]].push_back(char(i));
        }
        sort(v.begin(),v.end(),greater<int>());
        // disvec(v);
        s="";
        // int t=0;
        for(int i=0;;i++){
            if(i>0 && v[i]==v[i-1]){
                continue;
            }
            if(v[i]<=0){
                break;
            }

            // for(int j=0;j<m[v[i]].size();j++){
            for(auto x:m[v[i]]){
                for(int k=0;k<v[i];k++){
                    // cout<<x;
                    s.push_back(x);
                }
            }
            // s+=m[v[i]];
            // cout<<m[v[i]]<<" ";
        }
        return s;
    }
};
