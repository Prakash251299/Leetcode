class Solution {
public:
    void fun(vector<int>&v,int i,int a,int &sum){
        if(i>=v.size()){
            return;
        }
        
        for(;i<v.size();i++){
            a^=v[i];
            sum+=a;
            fun(v,i+1,a,sum);
            a^=v[i];
        }
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int a=0,sum=0,i=0;
        fun(nums,i,a,sum);
        return sum;
    }
};
