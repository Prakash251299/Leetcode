class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int neg=1,pos=1,max=nums[0],ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                neg=1;pos=1;
                ans=0;
            }
            if(nums[i]>0){
                neg = neg*nums[i];
                pos = pos*nums[i];
                ans = pos;
            }
            if(nums[i]<0){
                int t = neg;
                neg = pos*nums[i];
                if(t>=0){
                    pos = 1;
                    ans=nums[i];
                }else{
                    pos = t*nums[i];
                    ans = pos;
                }
            }
            if(ans>max){
                max = ans;
            }
        }
        return max;
    }
};
