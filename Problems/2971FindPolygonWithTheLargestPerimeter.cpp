class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long>v(nums.size()+1,0);
        long long max = -1;
        sort(nums.begin(),nums.end());
        v[0] = nums[0];
        v[1] = nums[1]+v[0];
        for(int i=2;i<nums.size();i++){
            // if(i!=0 && i!=1){
                if(v[i-1]>nums[i]){
                    if(v[i-1]+nums[i]>max){
                        max = v[i-1]+nums[i];
                    }
                }
            // }
            v[i]=v[i-1]+nums[i];
        }
        return max;
    }
};
