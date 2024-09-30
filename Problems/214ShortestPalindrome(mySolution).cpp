class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }

    int kmp(string s){
        vector<int>v(s.length(),0);
        int i=0,j=1;
        while(1){
            if(j>=s.size()){
                break;
            }
            if(s[j]=='*'){
                i=0;j++;
            }
            if(s[i]!=s[j]){
                if(i==0){
                    j++;
                }else{
                    i=v[i-1];
                }
            }else{
                i++;v[j]=i;j++;
            }
        }
        int m = v.back();
        return m;
    }

    string shortestPalindrome(string s) {
        if(s.size()==0||s.size()==1){
            return s;
        }
        string res = string(s.rbegin(),s.rend());
        string t = s+"*"+res;
        int k = kmp(t);
        t = "";
        // for(int i=k;i<s.size();i++){
        //     t = s[i] + t;
        // }


        t = s.substr(k,s.size()-1);
        reverse(t.begin(),t.end());

        t = t + s;
        return t;
    }
};
