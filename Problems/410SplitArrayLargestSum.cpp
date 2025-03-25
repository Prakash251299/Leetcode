class Solution {
public:
    int minimum(vector<int>v){
        int min=100000000;
        for(auto x:v){
            if(x<min){
                min = x;
            }
        }
        return min;
    }
    int minSum(vector<int>nums,int mid,int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                return 0;
            }
            if(k<=0){
                return 0;
            }
            if(sum+nums[i]>mid){
                k--;sum = nums[i];
                if(k<=0){
                    return 0;
                }
            }else{
                if(sum+nums[i]==mid){
                    k--;sum=0;
                }else{
                    sum+=nums[i];
                }
            }
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int min = minimum(nums),max=0;
        for(int i=0;i<nums.size();i++){
            max+=nums[i];
        }
        int i=min,j=max;
        int best=0;
        while(i<=j){
            int mid = (i+j)/2;
            if(minSum(nums,mid,k)){
                j = mid-1;
                best = mid;
            }else{
                i = mid+1;
            }
        }
        return best;
    }
};
