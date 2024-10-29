class Solution {
public:
    void orFun(vector<int>v,int &res,int i,int maxOr,int curr){
        if(i>=v.size()){
            return;
        }
        // if(res==maxOr){

        // }
        orFun(v,res,i+1,maxOr,curr);
        curr=curr|v[i];
        if(curr==maxOr){
            res++;
        }
        orFun(v,res,i+1,maxOr,curr);
        return;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(auto x:nums){
            maxOr = x|maxOr;
        }
        cout<<maxOr;
        int res = 0;
        orFun(nums,res,0,maxOr,0);
        return res;
    }
};
