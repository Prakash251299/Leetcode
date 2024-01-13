class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        int count=0;
        for(auto a:s){
            ++m[a];
        }
        for(auto x:t){
            if(m[x]>0){
                --m[x];
            }else{
                count++;
            }
        }
        return count;
    }
};
