class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>m;
        for(auto x:allowed){
            m[x] = 1;
        }
        int c = words.size();
        for(auto x:words){
            for(auto y:x){
                if(m[y]!=1){
                    c--;
                    break;
                }
            }
        }
        return c;
    }
};
