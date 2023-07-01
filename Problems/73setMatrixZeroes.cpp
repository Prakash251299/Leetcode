class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int a[m];
        int b[n],i=0,j=0;
        for(i=0;i<m;i++){
            a[i] = 1;
        }
        for(i=0;i<n;i++){
            b[i] = 1;
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    a[i]=0;
                    break;
                }
                // cout<<"hi";
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(matrix[j][i]==0){
                    b[i]=0;
                    break;
                }
                // cout<<"hi";
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(a[i]==0 || b[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};