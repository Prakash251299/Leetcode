class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max=0,start=0,c=0;
        for(int i=0;i<mat.size();i++){
            c=0;
            for(int j=0;j<mat[0].size();j++){
                c+=mat[i][j];
            }
            if(c>max){
                max = c;
                start = i;
            }
        }
        return {start,max};
    }
};
