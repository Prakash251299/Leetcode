class Solution {
public:
    int mod=1000000007;
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    void compressArr(vector<int>&arr){
    vector<int>nums=arr;
    /*unordered_map<int,vector<int>>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]].push_back(i);
    }*/
    //display(m);
    sort(arr.begin(),arr.end());
    vector<int>v;
    v.push_back(1);
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]){
            v.push_back(v[i-1]);
        }else{
            v.push_back(v[i-1]+1);
        }
    }
    //display(v);
    unordered_map<int,int>valMap;
    for(int i=0;i<arr.size();i++){
        valMap[arr[i]]=v[i];
    }
    for(int i=0;i<nums.size();i++){
        arr[i]=valMap[nums[i]];
    }
    //display(v);
        
    }

    void compressDivisorTable(vector<vector<int>>&divisorTable){
        for(int i=0;i<divisorTable.size();i++){
            if(divisorTable.size()!=0)
            compressArr(divisorTable[i]);
        }
    }
    
    int getParentCount(vector<int>&bit,int n){
    long long sum=0;
    while(n>0){
        sum=(long long)(sum+bit[n])%mod;
        n-=n&-n;
    }
    return sum;
}

void propagate(vector<int>&bit,int n,int val){
    while(n<=bit.size()-1){
        bit[n]=(long long)(bit[n]+val)%mod;
        n+=n&-n;
    }
}

int getIncreasingSubsequenceCount(vector<int>&arr,int n) {
    //vector<int>arr({1,2,3,6,3,7,8});
    // vector<int>arr({1,2,3,6});
    vector<int>bit(n,0);
    long long tot = 0;
    for(auto x:arr){
        long long sum=((long long)getParentCount(bit,x-1)+1)%mod;
        propagate(bit,x,sum);
        tot=(long long)(tot+sum)%mod;
    }
    //cout<<tot;
    return tot;
}
    void storeAllDivisors(vector<vector<int>>&divTable,int x){
        int i=1,j=x;
        while(i<=sqrt(x)){
            if(x%i!=0){
                i++;continue;
            }
            j=x/i;
            if(i==j){
                divTable[i].push_back(x);
                break;
            }
            divTable[i].push_back(x);
            divTable[j].push_back(x);
            i++;
        }
    }

    int getSubsCountMultiples(vector<int>&subsCount,int a){
        int i=2;
        long long count=0;
        int ind=a*i;
        //cout<<subsCount.size()<<"; gcd: "<<a/i<<"\n";
        while(ind<subsCount.size()){
            count=(count+subsCount[ind])%mod;
            i++;
            ind=a*i;
        }
        //cout<<"multiple sum: "<<count<<"\n";
        return count;
    }
    
    int totalBeauty(vector<int>& nums) {
        //cout<<getIncreasingSubsequenceCount(nums);
        int maxv=*max_element(nums.begin(),nums.end());
        vector<vector<int>>divisorTable(maxv+1);
        for(auto x:nums){
            storeAllDivisors(divisorTable,x);
        }

        // compression of divisorTable 
        compressDivisorTable(divisorTable);
        
        //display(divisorTable);
        vector<int>subsCount(maxv+1,0);
        for(int i=1;i<divisorTable.size();i++){
            if(divisorTable[i].size()==0){
                continue;
            }
            int maxi=*max_element(divisorTable[i].begin(), divisorTable[i].end());
            subsCount[i]=getIncreasingSubsequenceCount(divisorTable[i],maxi);
        }
        //display(subsCount);
        for(int i=subsCount.size()-2;i>0;i--){
            int extra=getSubsCountMultiples(subsCount,i);
            subsCount[i]=(subsCount[i]-extra+mod)%mod;
        }
        //display(subsCount);
        long long totalSum=0;
        for(int i=0;i<subsCount.size();i++){
            totalSum=(totalSum+(1LL*i*subsCount[i])%mod)%mod;
        }
        return totalSum;
    }
};
