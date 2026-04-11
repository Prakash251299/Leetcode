class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,odd=0,res=0,temp=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0){
                odd++;
                if(odd==k){
                    temp=0;
                    while(i<=j){
                        temp++;
                        if(nums[i]%2!=0){
                            i++;break;
                        }
                        i++;
                    }
                    res+=temp;
                    odd--;
                }
            }else{
                res+=temp;
            }
        }
        return res;
    }
};
