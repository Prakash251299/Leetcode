class Solution {
public:
    bool isSubsequence(string s, string t) {
        int flag=0,j=0;
        for(int i=0;i<s.size();i++){
            flag=0;
            for(;j<t.size();j++){
                if(s[i]==t[j]){
                    flag=1;
                    j++;
                    break;
                }
            }
            if(flag==0){
                return false;
            }
        }
        
        return true;
    }
};
