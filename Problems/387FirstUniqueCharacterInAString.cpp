class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(123,0);
        for(int i=0;i<s.size();i++){
            ++v[s[i]];
        }
        for(int i=0;i<s.size();i++){
            if(v[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
