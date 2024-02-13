class Solution {
public:
    int pallindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        string s="";
        for(auto s:words){
            if(pallindrome(s)){
                return s;
            }
        }
        return "";
    }
};
