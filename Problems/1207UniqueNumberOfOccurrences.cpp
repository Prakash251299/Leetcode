class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        unordered_map<int,int>m1;
        for(int i=0;i<arr.size();i++){
            ++m[arr[i]];
        }
        for(auto x:m){
            cout<<m[x.first]<<"\n";
            if(m1[x.second]>0){
                return false;
            }
            ++m1[x.second];
        }
        return true;
    }
};
