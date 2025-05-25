class Solution {
public:
    int checkPalindrome(string s){
        // cout<<s<<"\n";
        int i=0,j=s.size()-1;
        for(;i<=j;){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;j--;
        }
        return 1;
    }
    string reverse(string s){
        string s1="";
        for(int i=s.size()-1;i>=0;i--){
            s1.push_back(s[i]);
        }
        return s1;
    }
    int longestPalindrome(vector<string>& words) {
        map<string,int>m;
        for(auto x:words){
            ++m[x];
        }
        int mid=0,sum=0;
        for(auto x:m){
            if(x.second!=0){
                if(checkPalindrome(x.first)==1){
                    if(x.second%2==0){
                        sum+=x.second;
                    }else{
                        if(mid==0){
                            sum+=x.second;
                            mid=1;
                        }else{
                            sum+=(x.second-1);
                        }
                    }
                }else{
                    string rev = reverse(x.first);
                    sum+=(min(x.second,m[rev]))*2;
                    m[x.first]=0;
                    m[rev]=0;
                }
            }

        }
        // cout<<m["hi"];
        return sum*2;
    }
};
