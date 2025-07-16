class Solution {
public:
    int fun(vector<int>& coins, int a,int h,map<int,int>&dp,int flag){
        if(a==0){
            return 1;
        }
        for(int i=0;i<coins.size();i++){
            int t = a-coins[i];
            if(t<0){
                if(dp[a]<=0){dp[a] = -1;}
                continue;
            }
            if(t!=0 && (dp[t]==-1 || dp[t]>0)){
                if(dp[t]>0){
                    dp[a] = dp[a]>0?min(dp[a],dp[t]+1):dp[t]+1;
                    continue;
                }
                if(dp[t]<0){
                    if(dp[a]<=0){
                        dp[a] = -1;
                    }
                }
                continue;
            }
            flag=fun(coins,t,h+1,dp,flag);
            if(flag==0){
                if(dp[a]==0){dp[a]=-1;}
            }else{
                if(dp[a]<=0){
                    dp[a] = dp[t]+1;
                }else{
                    dp[a]=min(dp[a],dp[t]+1);
                }
            }
        }
        if(dp[a]>0){return 1;}
        return 0;
    }

    int coinChange(vector<int>& coins, int amount) {
        map<int,int>dp;
        int flag = fun(coins,amount,0,dp,0);
        if(flag==0){
            return -1;
        }
        return dp[amount];
    }
};
