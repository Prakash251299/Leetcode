class Solution {
public:
    int minimumDeletions(string s) {
        int res=0,a=0,b=0,min=10000000;
        for(auto x:s){
            if(x=='a'){
                a++;
            }
            // cout<<x;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                a--;
            }
            if(a+b<min){
                min=a+b;
            }
            if(s[i]=='b'){
                b++;
            }
        }
        return min;
    }
};
