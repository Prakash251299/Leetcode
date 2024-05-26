class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1,0); // For trusting persons
        vector<int>v1(n+1,0); // For trusted persons
        for(auto x:trust){
            ++v[x[0]];
            ++v1[x[1]];
        }
        for(int i=1;i<=n;i++){
            // If a person doesn't trust anyone and trusted by all then he/she is the judge
            if(v[i]==0 and v1[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
