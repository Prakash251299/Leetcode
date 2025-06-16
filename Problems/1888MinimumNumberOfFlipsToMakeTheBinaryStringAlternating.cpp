class Solution {
public:
    int minFlips(string s) {
        if(s.size()==1){
            return 0;
        }
        string s0 = "0";
        string s1 = "1";
        int n = s.size();
        for(int i=1;i<(n+n);i++){
            if(s0[i-1]=='0'){
                s0+='1';
                s1+='0';
                continue;
            }
            s0+='0';
            s1+='1';
        }
        // cout<<"s0: "<<s0<<"\n";
        // cout<<"s1: "<<s1<<"\n";
        int count=0,min=n;
        for(int i=0;i<s.size();i++){
            if(s0[i]!=s[i]){
                count++;
            }
        }
        min = count;
        s+=s;
        for(int i=1;i<n;i++){
            if(s[i-1]!=s0[i-1]){
                count--;
            }
            if(s[i+n-1]!=s0[i+n-1]){
                count++;
            }
            int k = n-count;
            if(k>count){
                k = count;
            }
            if(k<min){
                min = k;
            }
        }
        return min;
    }
};
