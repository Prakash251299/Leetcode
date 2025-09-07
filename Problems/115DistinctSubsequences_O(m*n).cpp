class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
    }
    int mod=1000000000;
    //int mod=2147483647;
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][t.size()]=1;
        }
        //display(dp);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                //cout<<i<<","<<j<<": ";
                //cout<<s[i]<<","<<s[j]<<"\n";
                if(s[i]==t[j]){
                   
                        dp[i][j]=(dp[i+1][j]+dp[i+1][j+1])%mod;
                   // }
                }else{
                    dp[i][j]=dp[i+1][j];
                }
                //cout<<dp[i][j]<<"\n";
            }
        }
       // display(dp);
        return dp[0][0];
    }
};
