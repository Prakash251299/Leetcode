class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res=0;
        int hare=0,turtle=0;
        if(nums.size()==2){
            return nums[0];
        }
        int i=0;
        turtle = nums[0]; // 1
        hare = nums[nums[0]]; // 3
        while(1){
            if(nums[hare]==nums[turtle]){
                turtle = 0;
                while(1){
                    if(nums[turtle]==nums[hare]){
                        return nums[turtle];
                    }
                    turtle = nums[turtle];
                    hare = nums[hare];
                }
            }
            turtle = nums[turtle];
            hare = nums[nums[hare]];
        }
        return res;
    }
};
