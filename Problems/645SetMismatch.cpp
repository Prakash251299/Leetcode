class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>v;
        // int max=nums.size()-1;
        for(auto x:nums){
            if(m[x]>0){
                v.push_back(x);
            }
            ++m[x];
        }
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i=1;i<=nums.size();i++){
            if(m[i]==0){
                v.push_back(i);
                break;
            }
        }
        return v;
    }
};
