class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,0));
        v[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                int add=0;
                if(i-1>=0){
                    add+=v[i-1][j];
                }
                if(j-1>=0){
                    add+=v[i][j-1];
                }
                v[i][j]=add;
            }
        }
        return v[m-1][n-1];
    }
};
