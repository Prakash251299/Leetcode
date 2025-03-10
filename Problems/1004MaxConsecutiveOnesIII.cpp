class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0,i=0,j=0;
        for(j=0;j<nums.size();j++){
            if(c==k){
                break;
            }
            if(nums[j]==0){
                c++;
            }
        }
        if(j==nums.size()){
            return j-i;
        }
        int max = j-i;
        cout<<"J: "<<j<<" ";
        while(j<nums.size() && i<=j){
            if(nums[j]==1){
                if(j-i+1>max){
                    max = j-i+1;
                }
                j++;continue;
            }
            else{
                if(nums[i]==0){
                    i++;j++;continue;
                }else{
                    i++;continue;
                }
            }
        }
        return max;
    }
};
