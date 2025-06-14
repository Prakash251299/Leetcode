class Solution {
public:
    void fun(vector<int>&nums,int i,int j, int &res){
        if(i+1>=j){
            res = j;
            return;
        }
        int mid=(i+j)/2;
        if(nums[mid]<nums[i]){
            fun(nums,i,mid,res);
        }else{
            fun(nums,mid,j,res);
        }
        return;
    }
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int res=0;
        fun(nums,0,nums.size()-1,res);
        return nums[res];
    }
};
