class Solution {
public:
    int max(int a, int b){
        if(a>=b){
            return a;
        }
        return b;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>v(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    v[i][j] = v[i+1][j+1]+1;
                }else{
                    v[i][j] = max(v[i+1][j],v[i][j+1]);
                }
            }
        }
        return v[0][0];
    }
};
