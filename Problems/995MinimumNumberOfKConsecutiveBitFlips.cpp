class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int>v(nums.size(),0);
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count%2==0){
                if(nums[i]==0){
                    if(i+k-1>=nums.size()){
                        return -1;
                    }
                    count++;
                    v[i+k-1]=1;
                }
                count-=v[i];
            }else{
                if(nums[i]==1){
                    if(i+k-1>=nums.size()){
                        return -1;
                    }
                    count++;
                    v[i+k-1]=1;
                }
                count-=v[i];
            }
        }
        int res=0;
        for(auto x:v){
            res+=x;
        }
        return res;
    }
};
