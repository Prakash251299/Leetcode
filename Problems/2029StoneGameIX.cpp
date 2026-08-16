class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>v(3,0);
        for(auto x:stones){
            v[x%3]++;
        }
        if (v[0] % 2 == 0)
            return v[1] > 0 && v[2] > 0;
        else
            return abs(v[1] - v[2]) > 2;
    }
};
