class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(vector<vector<vector<int>>> &dp){
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp.size();j++){
                cout<<dp[i][j][i]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int fun(vector<vector<int>>&v,vector<vector<vector<int>>>&dp,int i1,int j1,int i2,int n){
        //if(wall==1)return -1;
        int j2=i1+j1-i2;
        if(i1>=n||j1>=n||i2>=n||j2>=n){
            return -1;
        }
        //cout<<"("<<i1<<","<<j1<<"),("<<i2<<","<<j2<<")\n";
        if(v[i1][j1]==-1||v[i2][j2]==-1){
            return -1;
        }
        if(i1==n-1&&j1==n-1){
            return v[i1][j1];
        }
        if(dp[i1][j1][i2]==-1){return -1;}
        if(dp[i1][j1][i2]>=0){
            return dp[i1][j1][i2];
        }
        int a = max({fun(v,dp,i1+1,j1,i2+1,n),fun(v,dp,i1,j1+1,i2+1,n),fun(v,dp,i1+1,j1,i2,n),fun(v,dp,i1,j1+1,i2,n)});
        if(a<0){
            dp[i1][j1][i2]=a;
            return a;
        }
        int temp=0;
        if(i1==i2 && j1==j2){
            temp=v[i1][j1];
        }else{
            temp=v[i1][j1]+v[i2][j2];
        }
        dp[i1][j1][i2]=a+temp;
        return dp[i1][j1][i2];
    }

    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        //display(grid);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));
        dp[n-1][n-1][n-1]=grid[n-1][n-1];
       // dp[n-1][n-1][n-1]=1;
        int res = fun(grid,dp,0,0,0,n);
        //if(grid[n-1][n-1]==0){res--;}
       /* cout<<"res "<<res<<"\n";
        cout<<"dp: "<<dp[0][0][0]<<"\n";
        display(dp);*/
        if(res<=0)return 0;
        return res;
    }
};
