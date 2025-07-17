class Solution {
public:
    int fun(vector<int>&coins,int a, vector<vector<int>>&dp,int prev){
        if(a==0){return 1;}
        int res=0;
        for(int i=0;i<coins.size();i++){
           if(coins[i]<prev){continue;}
            int t= a-coins[i];
            if(t<0){dp[a][coins[i]]=-1;continue;}
            if(t>0){
            if(dp[a][coins[i]]>0){
                res+= dp[a][coins[i]];
                continue;
            }
            if(dp[a][coins[i]]<0){
                continue;
            }}
            
            int e = fun(coins,t,dp,coins[i]);
            if(e<0){
                dp[a][coins[i]]=e;
            }else{
                dp[a][coins[i]]+=e;
                res+=e;
            }
        }
        if(res<=0){
            return -1;
        }
        return res;
    }
    int change(int amount,vector<int>& coins) {
        if(amount==0){
            return 1;
        }
       vector<vector<int>>dp(5001,vector<int>(5001,0));
        dp[0][0]=1;
        int c=0;
        c=fun(coins,amount,dp,0);
        if(c<0){
            return 0;
        }
        return c;
    }
};
