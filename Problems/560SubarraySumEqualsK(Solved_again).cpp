class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>v;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            v.push_back(sum);
        }
        map<int,int>m;
        m[0]=1;
        int res=0;
        for(auto x:v){
            res+=m[x-k];
            ++m[x];
        }
        return res;
    }
};
