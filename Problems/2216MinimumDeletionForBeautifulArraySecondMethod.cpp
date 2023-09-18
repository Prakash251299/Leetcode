class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i=0,s=1,j=0,count=0;
        if(nums.size()==0){
            return 0;
        }
        for(i=0;i<nums.size()-1;){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                    i=j;
                }else{
                    i=j+1;
                    s++;
                    break;
                }
            }
        }
        if((nums.size()-count)%2!=0){
            count++;
        }
        return count;
    }
};