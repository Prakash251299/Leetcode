class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        int sum=0,count=0,start=0;
        unordered_map<int,int>m;
        m[0]=1;
        // for(auto x:m){
        //     cout<<x.first<<":"<<x.second<<"\n";
        // }
        // cout<<m[-1];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m[sum-k]>0){
                count+=m[sum-k];
            }
            ++m[sum];
        }
        return count;
    }
};
