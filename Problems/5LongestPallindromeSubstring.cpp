class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,j=0,k=0,st=0,end=0,max=0;
        for(i=0;i<s.size();i++){
            if(i+1<s.size() && s[i]==s[i+1]){
                if(max<2){
                    st = i;
                    end = i+1;
                    max = 2;
                }
                for(j=i-1,k=i+2;;){
                    if(j<0 || k>=s.size()){
                        break;
                    }else{
                        if(s[j]==s[k]){
                            if(k-j+1>max){
                                st = j;
                                end = k;
                                max = k-j+1;
                            }
                            j--;k++;
                        }else{
                            break;
                        }
                    }
                }
            }
            if(i+2<s.size() && s[i]==s[i+2]){
                if(max<3){
                    st = i;
                    end = i+2;
                    max = 3;
                }
                for(j=i-1,k=i+3;;){
                    if(j<0 || k>=s.size()){
                        break;
                    }else{
                        if(s[j]==s[k]){
                            if(k-j+1>max){
                                st = j; end = k; max = k-j+1;
                            }
                            j--;k++;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        return s.substr(st,end-st+1);
    }
};
