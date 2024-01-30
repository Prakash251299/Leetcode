class Solution {
public:

    int mod = pow(10,9)+7;
    void display(vector<vector<int>>v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
    }
    // vector<vector<int>>v(1001,vector<int>(1001,0));
    
    // void fun(int n,int k,int t,vector<vector<int>>v){
    //     for(i=t;;i++){
    //         if(v[i][n]==0){
    //             return 
    //         }

    //     }
    //     if(v[n][k]=0){
    //         return v[k][n];
    //     }
        

    // }
    
    int kInversePairs(int n, int k) {
        // for(int i=1;i<=n;i++){
        //     v[0][i]=1;
        // }
        // for(int i=0;i>=k;i++){
            // int t = k-(n-1);
            // if(t<0){
            //     t=0;
            // }
            // v[k][n]+=fun(n-1,k,t,v);
        // }
        
        
        
        
        // // k=2;

        // vector<vector<int>>v(1001,vector<int>(1001,0));

        vector<vector<int>>v(k+1,vector<int>(n+1,0));
        int i=0,j=0,curr=0;
        for(i=0;i<=n;i++){
            v[0][i] = 1;
        }
        // v[1][2] = 34;
        // display(v);
        v[0][0]=1;
        long t=0,remo=0;
        for(curr=1;curr<=n;curr++){
            t = 0,remo=0;
            for(j=0;j<=k;j++){
                if(curr>j){
                    t+=v[j][curr-1];
                    v[j][curr] = t%mod;
                }else{
                    t-=v[remo][curr-1];
                    t+=v[j][curr-1];
                    v[j][curr] = t%mod;
                    remo++;
                }
                if(t==0){
                    break;
                }
                // t=0;
                // remo=j-(curr-1);
                // if(remo<0){
                //     remo=0;
                // }
                // // if(v[j][curr]==0)
                // for(i=j-(curr-1);i<=j;i++){
                //     if(i<0){
                //         i=0;
                //     }

                //     if(v[remo][curr-1]==0){
                //         // cout<<"hi";
                //         break;
                //     }

                //     if(curr>remo){
                //         t += v[i][curr-1];
                //         v[j][curr] = t%mod;
                //     }else{
                //         t -= v[remo][curr-1];
                //         t += v[i][curr-1];
                //         v[j][curr] = t%mod;
                //         remo++;
                //     }
                // }
            }
        }
        // display(v);
        return v[k][n];
    }
};
