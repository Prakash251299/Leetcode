class Solution {
public:
    int characterReplacement(string s, int k) {
        int totC=0,mxC=0;
        vector<int>m(26,0);
        int i=0,res=0;
        for(int j=0;j<s.size();j++){
            m[s[j]-'A']++;
            mxC=m[0];
            totC=0;
            for(int n=0;n<26;n++){
                mxC=max(mxC,m[n]);
                totC+=m[n];
            }
            if(totC-mxC<=k){
                res=max(res,j-i+1);
            }
            else{
                while(totC-mxC>k){
                    m[s[i]-'A']--;i++;
                    mxC=m[0];
                    totC=0;
                    for(int n=0;n<26;n++){
                        mxC=max(mxC,m[n]);
                        totC+=m[n];
                    }
                }
                // No need to check for larger subarray as the previous valid subarray size is added by one character to make invalid then for making valid again we remove at least one character from front which makes the size at most the same as original valid subarray.
            }
        }
        return res;
    }
};
