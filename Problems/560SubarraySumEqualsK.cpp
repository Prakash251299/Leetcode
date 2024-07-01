class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

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
        // for(auto x:m){
        //     cout<<x.first<<":"<<x.second<<"\n";
        // }
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     if(sum==k){
        //         count++;
        //         sum-=nums[start];
        //         start++;
        //     }
        //     while(sum>k){
        //         sum-=nums[start];
        //         if(sum==k && start!=i){
        //             count++;
        //         }
        //         start++;
        //     }
        // }
        return count;
    }
};
