class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            int j=i;
            if(nums[i]==0){
                if(i+2<nums.size()){
                    nums[i] = 1;
                    nums[i+1] = ((nums[i+1]%2)+1)%2;
                    if(nums[i+1]==1){
                        j++;
                    }
                    nums[i+2] = ((nums[i+2]%2)+1)%2;
                    if(nums[i+2]==1){
                        j++;
                    }
                    i=j-1;
                }else{
                    return -1;
                }
                c++;
            }
        }
        return c;
    }
};
