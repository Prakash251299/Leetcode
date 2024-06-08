class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum%k==0 && i!=0){
                return true;
            }
            int t = sum%k;
            // if(k==0){
            //     if(m[k]>0){
            //         return true;
            //     }
            // }
            if(m[t]==0){
                m[t]=i+1;
            }else{
                if((i+1)-m[t]>1){
                    return true;
                }
            }
        }
        return false;
    }
};
