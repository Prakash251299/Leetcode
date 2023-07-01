class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count;
        for(int i=0;i<nums.size();i++){
            count.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    if(nums[i]>nums[j]){
                       count[i] = count[i]+1;
                    }
                }
                
            }
        }
        return count;
    }
};