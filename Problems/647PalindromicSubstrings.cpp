class Solution {
public:
    int getMatch(string s,int i,int j,int c){
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                i--;j++;c++;
            }else{
                break;
            }
        }
        return c;
    }
    int getPalindromeCountEven(string s,int i){
        int c=0;
        int j=i;
        i--;
        c += getMatch(s,i,j,c);
        return c;
    }

    int getPalindromeCountOdd(string s,int i){
        int c=0,j=i;
        c += getMatch(s,i,j,c);
        return c;
    }
    int countSubstrings(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            c+=getPalindromeCountOdd(s,i);
        }
        for(int i=1;i<s.size();i++){
            c+=getPalindromeCountEven(s,i);
        }
        return c;
    }
};
