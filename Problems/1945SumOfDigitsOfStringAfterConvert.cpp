class Solution {
public:
    int checkForSingleDigit(string a){
        if(a.size()==1){
            return 1;
        }
        return 0;
    }

    string integerToString(int a){
        string s="";
        while(a!=0){
            int t=a%10;
            a/=10;
            s+=(t+'0');
        }
        reverse(s.begin(),s.end());
        return s;
    } 

    string letterToInteger(string s){
        string r="";
        for(auto x:s){
            int t=0;
            t+=x-'a'+1;
            r += integerToString(t);
        }
        return r;
    }

    int sum(string s){
        int r = 0;
        for(auto x:s){
            // cout<<x;
            r=r+(x-'0');
        }
        // cout<<r;
        return r;
    }

    int stoi(string s){
        int r=0,t=pow(10,s.size()-1);
        for(auto x:s){
            r=r+(x-'0')*t;
            t/=10;
        }
        return r;
    }

    int getLucky(string s, int k) {
        int i=0;
        string t = letterToInteger(s);
        while(i<k){
            t = integerToString(sum(t));
            int c = checkForSingleDigit(t);
            if(c==1){
                return stoi(t);
            }
            i++;
        }
        return stoi(t);
    }
};
