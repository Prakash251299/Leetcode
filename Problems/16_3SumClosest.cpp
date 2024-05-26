class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j=0,k=0;
        int near=100000;
        int sum=0;
        for(int i=0;i<nums.size()-2;i++){
            // sum = nums[i];
            j = i+1;
            k = nums.size()-1;
            for(;j<k;){
                int a = nums[i]+nums[j]+nums[k];
                // cout<<a<<" ";
                int diff = target-a;
                if(diff<0){
                    diff = diff*-1;
                }
                if(diff<near){
                    near = diff;
                    cout<<near<<" ";
                }
                // sum+=nums[j];
                // sum+=nums[k];
                // if()
                if(a>target){
                    k--;
                }else{
                    if(a==target){
                        return 0;
                    }else{
                        j++;
                    }
                }
                // j++;
                // k--;
            }
        }
        return near;
    }
};
