class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v;
        vector<int>v1=nums;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        m[nums[0]]=0;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                m[nums[i]] = count;
            }
                count++;
        }
        for(int i=0;i<nums.size();i++){
            v.push_back(m[v1[i]]);
        }
        return v;
    }
};
