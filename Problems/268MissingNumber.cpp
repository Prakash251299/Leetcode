class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = 0;
        for(auto x:nums){
            if(max < x){
                max = x;
            }
        }
        vector<int>v(max+1,0);
        for(auto x:nums){
            ++v[x];
        }
        for(int i=0;i<=max;i++){
            if(v[i]==0){
                return i;
            }
        }
        return max+1;
    }
};
