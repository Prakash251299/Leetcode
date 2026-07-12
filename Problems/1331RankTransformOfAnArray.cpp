class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
        int i=1;
        for(auto x:v){
            if(m[x]==0){
                m[x]=i;
                i++;
            }
        }
        for(int i=0;i<arr.size();i++){
            v[i]=m[arr[i]];
        }
        return v;
    }
};
