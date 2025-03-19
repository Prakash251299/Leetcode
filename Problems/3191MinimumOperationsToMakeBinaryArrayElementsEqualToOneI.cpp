class Solution {
public:
    int reverse(int a){
        return ((a%2)+1)%2;
    }
    int minOperations(vector<int>& nums) {
        int c=0;
        // cout<<reverse(0);
        // cout<<reverse(1);
        // return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(i+2<nums.size()){
                    nums[i] = 1;
                    nums[i+1] = ((nums[i+1]%2)+1)%2;
                    nums[i+2] = ((nums[i+2]%2)+1)%2;
                }else{
                    return -1;
                }
                c++;
            }
        }
        return c;
    }
};
