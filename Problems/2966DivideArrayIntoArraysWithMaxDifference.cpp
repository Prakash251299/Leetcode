class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>v;
        vector<int>v1;
        sort(nums.begin(),nums.end());
        int i=0;
        for(auto x:nums){
            if(v1.size()>0 && x-v1[v1.size()-1]<=k){
                v1.push_back(x);
            }else{
                if(v1.empty()){
                    v1.push_back(x);
                }
            }
            if(i==2){
                if(v1.size()<3 or v1[2]-v1[0]>k){
                    v.clear();
                    return v;
                }
                v.push_back(v1);
                v1.clear();
                i=0;
            }else{
                i++;
            }
        }
        return v;
    }
};
