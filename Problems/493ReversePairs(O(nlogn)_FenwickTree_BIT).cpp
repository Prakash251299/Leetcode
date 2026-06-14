class Solution {
public:
    void display(vector<long long>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(unordered_map<long long,long long>&m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<" ";
        }
        cout<<"\n";
    }
    long long find(long long a,vector<long long>&bit,unordered_map<long long,long long>&rank){
        int r = rank[a]-1;
        int sum=0;
        while(r>0){
            sum+=bit[r];
            r-=(r&-r);
        }
        return sum;
    }
    void propagate(long long a,vector<long long>&bit){
        // cout<<a<<"\n";
        // return;
        while(a<bit.size()-1){
            bit[a]++;
            a+=(a&-a);
        }
        return;
    }
    int reversePairs(vector<int>& nums) {
        set<long long>s;
        vector<long long>v;
        for(int i=0;i<nums.size();i++){
            long long a = 1LL*nums[i]*2;
            s.insert(a);
            s.insert(nums[i]);
        }
        for(auto x:s){
            v.push_back(x);
        }
        sort(v.begin(),v.end()); 
        // display(v);
        unordered_map<long long,long long>rank;
        rank[0]=0;
        for(int i=0;i<v.size();i++){
            rank[v[i]]=i+1;
        }
        vector<long long>bit(rank.size()+1,0);
        long long res=0;
        for(int i=nums.size()-1;i>=0;i--){
            res+=find(nums[i],bit,rank);
            long long r = rank[1LL*nums[i]*2];
            propagate(r,bit);
        }
        return res;
    }
};
