class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        vector<int>v;
        for(auto x:nums1){
            ++m1[x];
        }
        for(auto x:nums2){
            ++m2[x];
        }
        nums1.clear();
        for(auto x:m1){
            nums1.push_back(x.first);
        }
        for(auto x:nums1){
            if(m1[x]>0 && m2[x]>0)
            if(m1[x]>=m2[x]){
                // for(int i=0;i<m2[x];i++)
                v.push_back(x);
            }else{
                // for(int i=0;i<m1[x];i++)
                v.push_back(x);
            }
        }
        return v;
    }
};
