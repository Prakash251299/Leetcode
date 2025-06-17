class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(auto x:nums){
            if(count%2==0){
                if(x==0){
                    count++;
                }
            }else{
                if(x==1){
                    count++;
                }
            }
        }
        return count;
    }
};
