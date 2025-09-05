class Solution {
public:
//     #include <bits/stdc++.h>
// using namespace std;
    void getmask(long long n,vector<long long>&m,vector<long long>&dp){
        dp[0]=0;
        for(long long i=1;i<=n;i++){
        long long x=i;
        //cout<<i<<": ";
        if(m[i]==1){
            dp[i]=i;continue;
        }
        long long maxv=0;
        while(x>0){
            long long setbit=x&-x;
            long long val=i-setbit;
            //cout<<val<<" ";
            /*if(m[val]==1){
                if(val>maxv){
                    maxv=val;
                }
            }*/
            if(dp[val]>maxv){
                maxv=dp[val];
            }
            x-=setbit;
        }
        //dp[i]=max(dp[i],maxv);
            if(maxv>dp[i]){
                dp[i]=maxv;
            }
        //cout<<"\n";
        }
    }
    
long long getMaxMask1(long long n,vector<int>&visited,vector<long long>&m,vector<long long>&dp){
    if(n<=0)return 0;
    /*if(m[n]==1){dp[n]=max(dp[n],n);visited[n]=1;}*/
    if(visited[n]==1 && m[n]!=0){
        return n;
    }
    if(visited[n]==1){
        return dp[n];
    }
    if(m[n]!=0){dp[n]=n;}
    
    long long x = n, maxv=0;
    while(x){
        long long mv = x&-x;
        long long y = n^mv;
        // cout<<mv<<":"<<y<<"\n";
        //if(visited[x]==1){x-=mv;continue;}
        
        
        if(m[y]==1){
            dp[n] = max(y,dp[n]);
            //break;
        }
        
        long long temp = getMaxMask1(y,visited,m,dp);
        //visited[temp] = 1;
        if(m[temp]==1){
            // dp[y] = max(temp,dp[y]);
            dp[n] = max(dp[y],dp[n]);
            visited[y] = 1;
            // break;
        }
        // dp[n] = y;
        // break;
        // maxv = max(maxv,temp);
        x-=mv;
    }
    // dp[n] = maxv;
    visited[n]=1;
    return dp[n];
}

long long maxBits(long long n){
    // n--;
    int c=0;
    while(n>0){
        n/=2;
        c++;
    }
    return c;
}
    
// vector<long long> caller(vector<int>&arr) {
long long caller(vector<int>&arr) {
    // vector<int>arr({1,2,3,4,5,6,7,8,9,10,11,12,13,14});
    long long maxv = *max_element(arr.begin(),arr.end());
    // n = 2000001; // This should be pow of 2
    // n = 8; // This should be pow of 2

    int n = maxv;
    n = maxBits(n);
    n = pow(2,n)-1;
    // cout<<n;
    
    // return 0;
    
    // vector<int>arr({1,7,8,9,10,11,13,14});
    //unordered_map<long long,long long>m;
    vector<long long>m(n+1,0);
    // vector<long long>dp(n+1,0);
    vector<long long>dp(n+1,0);
    for(auto x:arr){
        m[x]=1;
    }
    vector<int>visited(n+1,0);
    
    //getMaxMask(n,visited,m,dp);
    getmask(n,m,dp);
    
    /*cout<<"dp\n";
    for(auto x:dp){
        cout<<x<<" ";
    }*/
    // cout<<"\n";
    long long max=0;
    for(int i=0;i<arr.size();i++){
        int a = arr[i]^n;
        if(m[a]==0){a = dp[a];}
        // cout<<
        if(max<(1LL*a*arr[i])){
            max = (1LL*a*arr[i]);
        }
    }
    return max;
}

    long long maxProduct(vector<int>& nums) {
        // vector<long long>dp;
        return caller(nums);
        // long long max=0;
        // for(int i=0;i<nums.size();i++){
        //     if(max<(1LL*dp[nums[i]]*nums[i])){
        //         max = (1LL*dp[nums[i]]*nums[i]);
        //     }
        // }
        // return max;
    }
};
