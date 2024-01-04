class Solution {
public:
    int minOperations(vector<int>& nums) {
        int r=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            ++m[nums[i]];
        }
        for(auto x:m){
            int a = x.second;
            if(a==1){
                return -1;
            }
            r+=a/3;
            if(a%3>0){
                r++;
            }

            // if(a==1){
            //     return -1;
            // }
            // int rem = a%3;
            // if(rem==1){
            //     r += ((a-1)/3-1)+2;
            // }
            // if(rem==2){
            //     r += (a-2)/3+1;
            // }
            // if(rem==0){
            //     r += a/3;
            // }
        }
        return r;
    }
};
