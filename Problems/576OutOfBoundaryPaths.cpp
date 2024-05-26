class Solution {
public:
    long mod = pow(10,9)+7;
    int go(int m,int n,int i,int r,int c,vector<vector<vector<int>>> &v){
        long res=0;
        if(r>=0 and r<=m and c>=0 and c<=n){
            if(i==0){
                return 0;
            }else{
                if(v[r][c][i]==-1){
                    res += go(m,n,i-1,r+1,c,v);
                    res += go(m,n,i-1,r-1,c,v);
                    res += go(m,n,i-1,r,c-1,v);
                    res += go(m,n,i-1,r,c+1,v);
                    v[r][c][i] = res%mod;
                }else{
                    return v[r][c][i];
                }
            }
        }else{
            if(i==0){
                // max++;
                return 1;
            }
            // else{
            //     return 0;
            // }
        }
        return res%mod;
        // return res%(pow(10,9)+7);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> v(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        // cout<<v[0][0][0];
        long res=0,max=0;
        if(maxMove==0){
            return 0;
        }
        m--;
        n--;
        for(int i=1;i<=maxMove;i++){
            res = 0;
            res += go(m,n,i-1,startRow+1,startColumn,v);
            res += go(m,n,i-1,startRow-1,startColumn,v);
            res += go(m,n,i-1,startRow,startColumn+1,v);
            res += go(m,n,i-1,startRow,startColumn-1,v);
            // v[m][n][maxMove] = res%(pow(10.0,9.0)+7);
            v[startRow][startColumn][i] = res%mod;
            max += v[startRow][startColumn][i];
        }
        return max%mod;
    }
};
