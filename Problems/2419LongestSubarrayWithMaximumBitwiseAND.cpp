class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max=nums[0],c=1,res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
                c=1;
                res = 1;
                continue;
            }
            if(nums[i]==max){
                if(i+1>=nums.size()){
                    c++;
                    if(c>res){
                        res = c;
                        return res;
                    }
                }
                c++;
                continue;
            }
            if(nums[i]<max){
                if(c>res){
                    res = c;
                }
                c=0;
            }
        }
        return res;
    }
};
