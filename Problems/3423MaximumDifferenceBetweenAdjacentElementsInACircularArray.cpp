class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        vector<int> v = nums;
        for(auto x:v){
            nums.push_back(x);
        }
        int maxDiff=0;
        for(int i=0;i<nums.size()-1;i++){
            int t = nums[i]-nums[i+1];
            if(t<0){
                t*=-1;
            }
            if(t>maxDiff){
                maxDiff = t;
            }
        }
        return maxDiff;
    }
};
