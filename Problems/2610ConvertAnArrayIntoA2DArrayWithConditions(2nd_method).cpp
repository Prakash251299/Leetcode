class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // vector<int> f;
        // vector<int> t;
        // vector<vector<int>>v;
        // for(int i=0;i<=200;i++){
        //     f.push_back(0);
        // }
        // for(int i=0;i<nums.size();i++){
        //     ++f[nums[i]];
        // }
        // int m = *max_element(f.begin(),f.end());
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<f.size();j++){
        //         if(f[j]>0){
        //             t.push_back(j);
        //             --f[j];
        //         }
        //     }
        //     v.push_back(t);
        //     t.clear();
        // }
        // cout<<endl<<m;
        // return v;













        vector<int>v;
        vector<int>v1;
        vector<vector<int>>v2;
        for(int i=0;i<nums.size();i++){
            v.push_back(0);
        }
        unordered_map<int,int>m;
        // int count=0;
        for(int j=0;j<nums.size();j++){
            // if(count>=nums.size()){
            //     break;
            // }
            for(int i=0;i<nums.size();i++){
                // if(count>=nums.size()){
                //     break;
                // }
                if(v[i]==0){
                    if(m[nums[i]]==0){
                        v[i]=1;
                        // count++;
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
