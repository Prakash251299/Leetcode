class Solution {
public:
    int mod=1000000007;
    void display(vector<int>&v){
        for(int i=0;i<v.size();i++){
            if(v[i]==0)continue;
            cout<<i<<":"<<v[i]<<" ";
        }
        cout<<"\n";
    }

    void display1(vector<vector<int>>&v){
        for(int i=0;i<v.size();i++){
            int flag=0;
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==0)continue;
                flag=1;
                cout<<"["<<i<<","<<j<<"]:"<<v[i][j]<<" ";
            }
            if(flag==1)
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    int validity(int col,vector<vector<int>>&v,int i,int j){
        if(i-1>=0&&j-1>=0){
            if(v[i-1][j]==col||v[i][j-1]==col){
                return 0;
            }
        }
        if(i-1>=0){
            if(v[i-1][j]==col)return 0;
        }
        if(j-1>=0){
            if(v[i][j-1]==col)return 0;
        }
        return 1;
    }
    
    int callNextColumn(int i,int j,vector<vector<int>>&v,int &mask,int n, vector<unordered_map<int,int>>&dp,int total){
        if(dp[mask][j-1]!=0){
            return dp[mask][j-1];
        }
        mask=0;
        total=0;
        total=(total+solve(0,j,v,mask,n,dp,total))%mod;
        return total;
    }
    
    int solve(int i, int j, vector<vector<int>>&v,int &mask,int n, vector<unordered_map<int,int>>&dp,int total){
        total=0;
        if(j>=v[0].size()){
            return 1;
        }
        //int imask=stoi(mask);
        if(i>=v.size()){
            //display(v);
            int imask=mask;
            total=(total+callNextColumn(0,j+1,v,mask,n,dp,total))%mod;
            //cout<<"imask:"<<imask<<" j:"<<j<<"\n";
            if(j<v[0].size())
            dp[imask][j]=total;
            //display(v);
            return total;
        }
        
        for(int col=1;col<=3;col++){
            if(validity(col,v,i,j)){
                //cout<<i<<","<<j<<"\n";
                int temp=v[i][j];
                v[i][j]=col;
                int storedMask=mask;
                //int imask=0;
                //if(mask!="")
                //    imask=stoi(mask);
                //mask+=to_string(col);
                mask=mask*10+col;
                if(dp[mask][j]!=0)
                    total=(total+dp[mask][j])%mod;
                else
                total=(total+solve(i+1,j,v,mask,n,dp,total))%mod;
                mask=storedMask;
                v[i][j]=temp;
            }
        }
        return total;
    }
    int colorTheGrid(int m, int n) {
        int total=0;
        vector<vector<int>>v(m,vector<int>(n,0));
        int mask=0;
        vector<unordered_map<int,int>>dp(333);
        total=solve(0,0,v,mask,n,dp,total);
        //display1(dp);
        return total;
    }
    int numOfWays(int n) {
        return colorTheGrid(3,n);
    }
};
