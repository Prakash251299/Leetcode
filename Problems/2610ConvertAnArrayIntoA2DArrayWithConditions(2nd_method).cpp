class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> f;
        vector<int> t;
        vector<vector<int>>v;
        for(int i=0;i<=200;i++){
            f.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            ++f[nums[i]];
        }
        int m = *max_element(f.begin(),f.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<f.size();j++){
                if(f[j]>0){
                    t.push_back(j);
                    --f[j];
                }
            }
            v.push_back(t);
            t.clear();
        }
        cout<<endl<<m;
        return v;
    }
};
