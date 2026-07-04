class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            nums[i]=1;
            else
            nums[i]=0;
        }
        long long sum=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>(j-i+1)/2){
                    c++;
                }
            }
        }
        return c;
    }
};
