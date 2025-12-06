class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int count=0;
        long long tempSum=0;
        for(int i=0;i<nums.size()-1;i++){
            int x=nums[i];
            tempSum+=x;
            if(tempSum>=sum-tempSum){
                count++;
            }
        }
        return count;
    }
};
