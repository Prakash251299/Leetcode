class Solution {
public:
    int max(int a,int b){
        if(a>=b){return a;}
        return b;
    }
    int rob(vector<int>& nums) {
        int a = nums[0],b = nums[1],c=0;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        nums[2] += nums[0];
        for(int i=3;i<nums.size();i++){
            nums[i]+=max(nums[i-2],nums[i-3]);
        }
        if(nums[nums.size()-1]>=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        return nums[nums.size()-2];
    }
};
