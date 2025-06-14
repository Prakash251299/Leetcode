class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        v[v.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(i+2<nums.size()){
                int t=nums[i]+v[i+2];
                if(t>v[i+1]){
                    v[i] = t;
                }else{
                    v[i] = v[i+1];
                }
            }else{
                if(nums[i]>v[i+1]){
                    v[i] = nums[i];
                }else{
                    v[i] = v[i+1];
                }
            }
        }
        return v[0];
    }
};
