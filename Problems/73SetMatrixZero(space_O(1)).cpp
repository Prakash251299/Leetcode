class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstColZero=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){
                    if(matrix[i][j]==0){
                        firstColZero=1;
                    }
                    continue;
                }
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>0;j--){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstColZero)
        for(int j=0;j<matrix.size();j++){
            matrix[j][0]=0;
        }
    }
};
