class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size()-1;
        int max = 0;
        if(nums.size()==1){
            return true;
        }
        int maxInd = 0;
        for(int i=0;i<size;i++){
            if(max<nums[i]+i){
                max = nums[i]+i;
                maxInd = nums[i]+i;
            }
            if(nums[i]==0){
                if(maxInd==i){
                    return false;
                }
            }
            if(max>=size){
                return true;
            }
        }
        return false;
    }
};