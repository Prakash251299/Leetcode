class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=0;
        for(i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i<=0){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+i,nums.end());
        for(int j=i;j<=nums.size();j++){
            if(nums[j]>nums[i-1]){
                int t = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = t;
                return;
            }
        }
        return;
    }
};
