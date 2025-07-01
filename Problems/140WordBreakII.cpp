class Solution {
public:
    void fun(string &s,vector<string> &v,int i,map<string,int>&m,vector<map<string,int>>&dp,string res,vector<string>&a,bool &check){
        // if(res==true){
        //     return;
        // }
        if(i>=s.size()){
            check=true;
            a.push_back(res);
            return;
        }
        string str="";
        int j=i;        
        if(res!=""){
            res+=" ";
        }
        for(;i<s.size();i++){
            // if(res==true){return;}
            str+=s[i];
            if(m[str]==0){
                // dp[str] = -1;
                // dp[str]=j+1;
                continue;
            }
            // res+=str;
            // dp[str] = j;
            if(dp[j][str]==1){
                continue;
            }
            // if(res==false)
            fun(s,v,i+1,m,dp,res+str,a,check);
            if(check==true){
                dp[j][str]=2;
            }else{
                dp[j][str]=1;
            }
            // res-=str;
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>&wordDict) {
        map<string,int>m;
        vector<map<string,int>>dp(s.size());
        for(auto x:wordDict){
            ++m[x];
        }
        string res="";
        vector<string>a;
        bool check=false;
        fun(s,wordDict,0,m,dp,res,a,check);
        return a;
    }
};
