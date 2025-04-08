class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>m;
        int i=0;
        for(i=nums.size()-1;i>=0;i--){
            ++m[nums[i]];
            if(m[nums[i]]>1){
                break;
            }
        }
        return (i+1+3-1)/3;
    }
};
