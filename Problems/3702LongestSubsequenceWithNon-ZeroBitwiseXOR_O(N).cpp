class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
            if(sum>0)break;
        }
        if(sum==0){
            return 0;
        }
        int a = 0;
        for(auto x:nums){
            a^=x;
        }
        if(a==0){
            return nums.size()-1;
        }
        return nums.size();
    }
};
