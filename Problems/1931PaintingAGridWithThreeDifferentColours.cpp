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
    
    //int callNextColumn(int i,int j,vector<vector<int>>&v,string &mask,int n, unordered_map<int, unordered_map<int, int>> &dp,int total){
    int callNextColumn(int i,int j,vector<vector<int>>&v,string &mask,int n, vector<unordered_map<int,int>>&dp,int total){
        int imask=stoi(mask);
        //cout<<"mask|"<<imask<<","<<j-1<<":"<<dp[imask][j-1]<<"\n";
        if(dp[imask][j-1]!=0){
            //cout<<"mask|";
            //cout<<imask<<","<<j-1<<":"<<dp[imask][j-1]<<"--"<<dp[imask][j]<<"\n";
            return dp[imask][j-1];
        }
        mask="";
        total=0;
        total=(total+solve(0,j,v,mask,n,dp,total))%mod;
        return total;
    }
    
    //int solve(int i, int j, vector<vector<int>>&v,string &mask,int n, unordered_map<int, unordered_map<int, int>> &dp,int total){
    int solve(int i, int j, vector<vector<int>>&v,string &mask,int n, vector<unordered_map<int,int>>&dp,int total){
        total=0;
        if(j>=v[0].size()){
            //display(v);
            //total++;
            return 1;
        }
        //int imask=stoi(mask);
        if(i>=v.size()){
            //display(v);
            int imask=stoi(mask);
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
                string storedMask=mask;
                mask+=to_string(col);
                int imask=stoi(mask);
                if(dp[imask][j]!=0)
                    total=(total+dp[imask][j])%mod;
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
        string mask="";
        //unordered_map<vector<int>,int>dp;
        //unordered_map<int, unordered_map<int, int>> dp;
        vector<unordered_map<int,int>>dp(33333);
        //vector<vector<int>>dp(,vector<int>(5000,0));
        total=solve(0,0,v,mask,n,dp,total);
        //display1(dp);
        return total;
    }
};
