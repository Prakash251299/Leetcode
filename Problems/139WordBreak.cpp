class Solution {
public:
    void fun(string &s,vector<string> &v,int i,map<string,int>&m,vector<map<string,int>>&dp,bool &res){
        if(res==true){
            return;
        }
        if(i>=s.size()){
            res=true;
            return;
        }
        string str="";
        int j=i;
        for(;i<s.size();i++){
            if(res==true){return;}
            str+=s[i];
            if(m[str]==0){
                // dp[str] = -1;
                // dp[str]=j+1;
                continue;
            }
            // dp[str] = j;
            if(dp[j][str]==1){
                continue;
            }
            if(res==false)
            fun(s,v,i+1,m,dp,res);
            dp[j][str]=1;
        }
        return;
    }
    bool wordBreak(string s, vector<string>&wordDict) {
        map<string,int>m;
        vector<map<string,int>>dp(s.size());
        for(auto x:wordDict){
            ++m[x];
        }
        bool res=false;
        fun(s,wordDict,0,m,dp,res);
        return res;
    }
};
