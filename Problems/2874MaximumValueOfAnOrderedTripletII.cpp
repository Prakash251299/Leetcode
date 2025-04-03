class Solution {
public:
    void getMaxRev(vector<int>&v,vector<int>&res){
        res[res.size()-1] = 0;
        for(int i = v.size()-2;i>=0;i--){
            if(res[i+1]>v[i+1]){
                res[i] = res[i+1];
            }else{
                res[i] = v[i+1];
            }
        }
    }
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>res(nums.size(),0);
        getMaxRev(nums,res);
        long long m = nums[0],max=0;
        for(int i=0;i<nums.size()-1;i++){
            long long max1 = (m-nums[i])*res[i];
            if(max1>max){
                max = max1;
            }
            if(nums[i]>m){
                m = nums[i];
            }
        }
        return max;
    }
};
