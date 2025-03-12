class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,a=0,b=0,c=0,count=0;
        while(j<s.size()){
            if(s[j]=='a'){
                a++;
            }
            if(s[j]=='b'){
                b++;
            }
            if(s[j]=='c'){
                c++;
            }
            if(a>0 && b>0 && c>0){
                count+=s.size()-j;
                if(s[i]=='a'){
                    a--;
                }
                if(s[i]=='b'){
                    b--;
                }
                if(s[i]=='c'){
                    c--;
                }
                i++;
                for(;i<j;i++){
                    if(a>0 && b>0 && c>0){
                        count+=s.size()-j;
                    }
                    else{
                        break;
                    }
                    if(s[i]=='a'){
                        a--;
                    }
                    if(s[i]=='b'){
                        b--;
                    }
                    if(s[i]=='c'){
                        c--;
                    }
                }
            }
            j++;
        }
        return count;
    }
};
