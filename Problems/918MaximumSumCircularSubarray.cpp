class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // If all are negetives
        int n=0,sum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                if(nums[i]>sum){
                    sum = nums[i];
                }
                n++;
            }
        }
        if(n==nums.size()){
            return sum;
        }

        // Generally
        int curr=0,min = INT_MAX,s=0,e=0,gs=0,ge=0;
        for(int i=0;i<nums.size();i++){
            if(curr+nums[i]>nums[i]){
                curr = nums[i];
                if(curr<min){
                    gs = i;
                    ge = i;
                    min = curr;
                }
                s = i;
                e = i;
            }else{
                curr+=nums[i];
                if(curr<min){
                    gs = s;
                    ge = i;
                    min = curr;
                }
                e = i;
            }
        }
        sum=0;
        for(int i=0;i<gs;i++){
            sum+=nums[i];
        }
        for(int i=nums.size()-1;i>ge;i--){
            sum+=nums[i];
        }
        long long s2=0, m=INT_MIN;
        for(auto x:nums){
            if((long long)s2+x>=0){
                s2+=x;
            }else{
                s2=0;
            }
            if(s2>m){
                m = s2;
            }
        }
        if(m>sum){
            return m;
        }
        return sum;
    }
};
