class Solution {
public:
    void display(vector<vector<vector<int>>>&dp){
        for(int i =0;i<dp.size();i++){
            //cout<<"("<<i<<",";
            for(int j=0;j<dp[0].size();j++){
                //cout<<j<<",";
                for(int k=0;k<dp[0].size();k++){
                    //cout<<k<<",";
                    
                        cout<<"("<<i<<","<<j<<","<<k<<"):";
                        cout<<dp[i][j][k]<<" ";
                    
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int fun(vector<vector<int>>&v,vector<vector<vector<int>>>&dp,int i1,int j1,int j2){
        //int j2=i1+j1-i2;
        int i2=i1;
        int n=v.size();
        int m=v[0].size();
        if(i1>=n||j1>=m||j2>=m||i1<0||j1<0||i2<0||j2<0){
            return -2;
        }
        if(i1==n-1){
            if(j1==j2){
                return v[i1][j1];
            }else{return v[i1][j1]+v[i2][j2];}
        }
        if(dp[i1][j1][j2]==-2){
            return -2;
        }
        if(dp[i1][j1][j2]>=0){
            return dp[i1][j1][j2];
        }
        int a =max({fun(v,dp,i1+1,j1-1,j2-1),fun(v,dp,i1+1,j1-1,j2),fun(v,dp,i1+1,j1-1,j2+1),fun(v,dp,i1+1,j1,j2-1),fun(v,dp,i1+1,j1,j2),fun(v,dp,i1+1,j1,j2+1),fun(v,dp,i1+1,j1+1,j2-1),fun(v,dp,i1+1,j1+1,j2),fun(v,dp,i1+1,j1+1,j2+1)});
        if(a<0){return -2;}
        int temp=0;
        if(j1==j2){
            temp=v[i1][j1];
        }else{
            temp=v[i1][j1]+v[i2][j2];
        }
        dp[i1][j1][j2]=temp+a;
        return temp+a;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        int res=fun(grid,dp,0,0,grid[0].size()-1);
        display(dp);
        return res;
    }
};
