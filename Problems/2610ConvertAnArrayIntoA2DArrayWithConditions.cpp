class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>v;
        vector<int>v1;
        vector<vector<int>>v2;
        for(int i=0;i<nums.size();i++){
            v.push_back(0);
        }
        unordered_map<int,int>m;
        for(int j=0;j<nums.size();j++){
            for(int i=0;i<nums.size();i++){
                if(v[i]==0){
                    if(m[nums[i]]==0){
                        v[i]=1;
                        m[nums[i]] = 1;
                        v1.push_back(nums[i]);
                    }
                }
            }
            if(v1.size()!=0)
            v2.push_back(v1);
            m.clear();
            v1.clear();
        }
        return v2;
    }
};
