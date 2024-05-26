class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int j=0,k=0;
        int near=100000;
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            j = i+1;
            k = nums.size()-1;
            for(;j<k;){
                int a = nums[i]+nums[j]+nums[k];
                // cout<<a<<" ";
                int diff = target-a;
                // cout<<a<<" "<<target<<" "<<diff<<"\n";
                if(diff<0){
                    diff = -1*diff;
                }
                if(diff<near){
                    near = diff;
                    cout<<near<<" ";
                    sum = a;
                }
                if(a>target){
                    k--;
                }else{
                    if(a==target){
                        return a;
                    }else{
                        j++;
                    }
                }
            }
        }
        return sum;
    }
};
