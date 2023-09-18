class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<int>v;
        int i=0;
        if(nums.size()==0){
            return 0;
        }
        v.push_back(nums[0]);
        for(i=1;i<nums.size();i++){
            if(nums[i]==v[v.size()-1]){
                if(v.size()%2==0){
                    v.push_back(nums[i]);
                }
            }
            else{
                v.push_back(nums[i]);
            }
        }
        if(v.size()%2!=0){
            v.pop_back();
        }
        return nums.size()-v.size();
    }
};