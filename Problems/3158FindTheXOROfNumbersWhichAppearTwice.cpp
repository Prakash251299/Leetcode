class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>m;
        int duplicate = 0;
        for(int i=0;i<nums.size();i++){
            ++m[nums[i]];
            if(m[nums[i]]>1){
                duplicate = nums[i]^duplicate;
            }
        }
        return duplicate;
    }
};
