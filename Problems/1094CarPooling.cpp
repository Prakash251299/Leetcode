class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>v(1000,0);
        for(auto x:trips){
            for(int i=x[1];i<x[2];i++){
                v[i]+=x[0];
            }
        }
        for(auto x:v){
            if(x>capacity){
                return false;
            }
        }
        return true;
    }
};
