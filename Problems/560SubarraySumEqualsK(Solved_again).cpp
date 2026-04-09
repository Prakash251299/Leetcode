class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>pr(nums.size(),0);
        pr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pr[i]=pr[i-1]+nums[i];
        }
        unordered_map<int,int>m;
        int c=0;
        m[0]=1;
        for(int i=0;i<pr.size();i++){
            if(m[pr[i]-k]>0){
                c+=m[pr[i]-k];
            }
            m[pr[i]]++;
        }
        return c;
    }
};
