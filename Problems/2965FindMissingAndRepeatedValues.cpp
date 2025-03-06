class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b;
        int n = grid.size()*grid.size();
        vector<int>v(n+1,0);
        for(auto x:grid){
            for(auto y:x){
                v[y] = v[y]+1;
                if(v[y]>1){
                    a = y;
                }
            }
        }
        for(int i=1;i<v.size();i++){
            if(v[i]==0){
                b = i;
                break;
            }
        }
        return {a,b};
    }
};
