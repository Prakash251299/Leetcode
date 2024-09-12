class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>v(26,0);
        for(auto x:allowed){
            v[x-'a']=1;
        }
        int c = words.size();
        for(auto x:words){
            for(auto y:x){
                if(v[y-'a']!=1){
                    c--;
                    break;
                }
            }
        }
        return c;
    }
};
