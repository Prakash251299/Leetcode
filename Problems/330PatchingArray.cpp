class Solution {
public:
    int getExtraNeeds(long long a,int n){
        int count=0;
        while(a<n){
            a=a+a+1;
            count++;
        }
        return count;
    }
    int minPatches(vector<int>& nums, int n) {
        long long sum=0;
        int i=0,count=0;
        while(i<nums.size()){
            if(sum>=n){break;}
            
            if(nums[i]<=sum+1){
                sum=sum+nums[i];
                i++;
            }else{
                count++;
                sum=sum+sum+1;
            }
        }
        if(sum<n){
            count+=getExtraNeeds(sum,n);
        }
        return count;
    }
};
