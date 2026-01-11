class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>repeatStr(26,0);
        vector<int>kVal(26,k);
        int maxV=0;
        for(int j=0;j<s.size();j++){
            char x = s[j];
            for(int i=0;i<26;i++){
                if(int(x-'A')==i){
                    repeatStr[i]++;
                    if(repeatStr[i]>maxV){
                        maxV = repeatStr[i];
                    }
                }else{
                    if(kVal[i]>0){
                        kVal[i]--;
                        repeatStr[i]++;
                        if(repeatStr[i]>maxV){
                            maxV = repeatStr[i];
                        }
                    }else{
                        int m = j-repeatStr[i];
                        int flag=0;
                        while(m<j){
                            if(s[m]==char(i+int('A'))){
                                repeatStr[i]--;flag=1;
                            }else{
                                break;
                            }
                            m++;
                        }
                    }
                }
            }
        }
        return maxV; 
    }
};
