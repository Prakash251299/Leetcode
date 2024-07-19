class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int k = validity(matrix,i,j);
                // cout<<matrix[i][j]<<" "<<k<<"\n";
                if(k==1){
                    v.push_back(matrix[i][j]);
                }
            }
        }
        return v;
    }
    int validity(vector<vector<int>>& v,int i,int j){
        for(int k=0;k<v.size();k++){ // column
            if(v[k][j]>v[i][j]){
                return 0;
            }
        }
        for(int k=0;k<v[i].size();k++){ // Row
            if(v[i][k]<v[i][j]){
                return 0;
            }
        }
        cout<<v[i][j];
        return 1;
    }
};
