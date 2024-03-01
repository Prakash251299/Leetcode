class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // string s="";
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                s[i]='0';
                count++;
            }
        }
        if(count==0){
            return s;
        }else{
            s[s.size()-1]='1';
        }
        for(int i=1;i<count;i++){
            s[i-1]='1';
        }
        return s;
    }
};
