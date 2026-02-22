class Solution {
public:
    int maxPal(string s,int i,int j){
        int c=0;
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                c=c+2;
            }else{
                int m1=0,m2=0,i1=i-1,j1=j,i2=i,j2=j+1;
                while(i1>=0 && j1<s.size()){
                    if(s[i1]==s[j1]){
                        m1=m1+2;
                    }else{break;}
                    i1--;j1++;
                }
                while(i2>=0 && j2<s.size()){
                    if(s[i2]==s[j2]){
                        m2=m2+2;
                    }else{break;}
                    i2--;j2++;
                }
                c = c+max(m1,m2);
                break;
            }
            i--;j++;
        }
        return c;
    }

    int almostPalindromic(string s) {
        int res=0;
        for(int i=1;i<s.size();i++){
            int m1=maxPal(s,i-1,i+1)+1;
            int m2=maxPal(s,i-1,i);
            int m3=max(m1,m2);
            res = max(res,m3);
        }
        if(res==s.size())return res;
        return res+1;
    }
};
