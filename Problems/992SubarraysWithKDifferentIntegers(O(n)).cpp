class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int i=0,j=0,count=0;
        unordered_map<int,int>m;
        for(;j<nums.size();j++){
            m[nums[j]]++;
            if(m.size()<=k){
                count+=j-i+1;
            }else{
                while(i<=j && m.size()>k){
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
                count+=j-i+1;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l=0,r=0;
        l = subarraysWithAtMostKDistinct(nums,k);
        r = subarraysWithAtMostKDistinct(nums,k-1);
        // cout<<"l:"<<l<<endl;
        // cout<<"r:"<<r;
        return l-r;
    }
};
