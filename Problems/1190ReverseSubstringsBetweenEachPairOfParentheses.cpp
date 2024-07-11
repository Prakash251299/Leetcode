class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.size(),c=0;
        string res="";
        for(int i=0;i<len;i++){
            if(s[i]!=')'){
                res+=s[i];
            }else{
                int j=i-1-c;
                string temp="";
                c++;
                while(res[j]!='('){
                    temp+=res[j];
                    // res[j]=' ';
                    res.erase(j,1);
                    j--;
                }
                // res.erase(j,1);
                // if(res.size()>1){
                    res.erase(j,1);
                // }
                // res[j]='';
                res+=temp;
                c++;
            }

        }
        return res;
    }
};
