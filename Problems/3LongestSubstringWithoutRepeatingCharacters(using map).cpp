class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int i=0,j=0,max=0;
        for(;j<s.size();j++){
            if(m[s[j]]>0){
                for(;i<j;i++){
                    if(s[i]==s[j]){
                        --m[s[i]];i++;break;
                    }
                    --m[s[i]];
                }
            }
            if(j-i+1>max){
                max = j-i+1;
            }
            ++m[s[j]];
        }
        return max;
    }
};
