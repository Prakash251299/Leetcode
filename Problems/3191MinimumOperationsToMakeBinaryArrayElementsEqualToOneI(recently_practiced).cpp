class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==1){
                continue;
            }
            c++;
            for(int j=i;j<i+3;j++){
                if(nums[j]==0){
                    nums[j] =1;
                }else{
                    nums[j] = 0;
                }
            }
        }
        for(auto x:nums){
            if(x==0){
                return -1;
            }
        }
        return c;
    }
};
