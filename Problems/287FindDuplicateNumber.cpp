class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            if(nums[i]<0){
                a = -1*a;
            }
            if(nums[a]<0){
                return a;
            }else{
                nums[a] = -1*nums[a];
            }
        }
        return 0;
    }
};