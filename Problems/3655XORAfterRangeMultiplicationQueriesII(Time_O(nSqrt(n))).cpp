class Solution {
public:

    int mod = 1000000007;

void display(vector<int>&v){
    for(auto x:v){
        cout<<x<<" ";
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

int binaryExponentiation(int a,int n){
    if(n<=0)return 1;
    long long temp=a%mod;
    if(n%2==0){
        temp = binaryExponentiation(a,n/2);
        temp = (1LL*temp*temp)%mod;
    }else{
        temp = binaryExponentiation(a,n/2);
        temp = (1LL*((1LL*temp*temp)%mod)*a)%mod;
    }
    return temp;
}

int modInv(int a,int b){
    return binaryExponentiation(a,b-2);
}

void sqDiffArr(int l,int r,int k,int v,vector<vector<int>>&diffArr){
    int mi = modInv(v,mod);
    diffArr[k][l]=(1LL*diffArr[k][l]*v)%mod;
    long long ind = k*((r-l)/k+1)+l;
    // if(l==0){
    //     ind = (r/k+1)*k;
    // }
    
    // cout<<ind<<"\n";
    if(ind<diffArr[0].size()){
        diffArr[k][ind]=(1LL*diffArr[k][ind]*mi)%mod;
    }
    // if(r+1<diffArr[0].size()){
    //     diffArr[k][r+1]=(1LL*diffArr[k][r+1]*mi)%mod;
    // }
    
    
    
    return;
}

void noramlDiffArr(int l,int r,int k,int v,vector<int>&nums){
    for(int i=l;i<=r;i+=k){
        nums[i]=(1LL* nums[i]*v)%mod;
    }
}

int caller(vector<int>& nums, vector<vector<int>>& queries) {
    int sq = sqrt(nums.size());
    vector<vector<int>>diffArr(sq+1,vector<int>(nums.size(),1));
    for(auto x:queries){
        int l = x[0];
        int r = x[1];
        int k = x[2];
        int v = x[3];
        if(k<=sq){
            sqDiffArr(l,r,k,v,diffArr);
        }else{
            noramlDiffArr(l,r,k,v,nums);
        }
    }
    
    // cout<<"Final DiffArr\n";
    // display(diffArr);
    // for(int i=1;i<diffArr.size();i++){
    //     for(int j=0;j<diffArr[i].size();j+=i){
    //         // if(j==0){mult = diffArr[i][0];continue;}
    //         if(j==0)continue;
    //         int mult=diffArr[i][j-i];
    //         diffArr[i][j] = (diffArr[i][j]*mult)%mod;
    //     }
    // }
    for(int i=1;i<diffArr.size();i++){
        for(int j=i;j<diffArr[i].size();j++){
            // if(j==0){mult = diffArr[i][0];continue;}
            // if(j==0)continue;
            int mult=diffArr[i][j-i];
            diffArr[i][j] = (1LL*diffArr[i][j]*mult)%mod;
        }
    }
    
    // cout<<"DiffArr multiplied\n";
    // display(diffArr);
    vector<int>v(diffArr[0].size(),1);
    for(int i=0;i<diffArr[0].size();i++){
        int temp = 1;
        for(int j=0;j<diffArr.size();j++){
            temp=(1LL*temp*diffArr[j][i])%mod;
            // cout<<diffArr[j][i]<<" ";
        }
        v[i] = temp;
        // break;
    }
    // cout<<"1D DiffArr\n";
    // display(v);
    
    
    
    // Multiplying the diffArr to original
    for(int i=0;i<nums.size();i++){
        nums[i]=(1LL*nums[i]*v[i])%mod;
    }
    
    // cout<<"Final nums\n";
    // display(nums);
    int res=nums[0];
    for(int i=1;i<nums.size();i++){
        res^=nums[i];
    }
    // cout<<"XOR: "<<res;
    return res;
}
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res = caller(nums,queries);
        return res;
    }
};
