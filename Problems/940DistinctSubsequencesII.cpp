class Solution {
public:
    int mod=1000000007;
    int distinctSubseqII(string s) {
        vector<long long>countSubs(s.size()+1,0);
        unordered_map<char,long long>m;
        countSubs[0]=1;
        for(int i=1;i<=s.size();i++){
            long long subtractor=0;
            if(m[s[i-1]]>=1){
                subtractor= (countSubs[m[s[i-1]]-1]+mod)%mod;
            }
            countSubs[i]=((countSubs[i-1]*2)%mod-subtractor+mod)%mod;
            m[s[i-1]]=i;
        }
        return (countSubs[countSubs.size()-1]-1+mod)%mod;
    }
};
