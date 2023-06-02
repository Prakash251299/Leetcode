class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size()-1,n=matrix[0].size()-1;
        int left=0,right=n,top=0,bottom=m;
        int i=0,j=0,k=0;
        vector<int> v;
        if(matrix.size()==1){
            v=matrix[0];
            return v;
        }
        j= top;
        while(left<=right || top<=bottom){
            j=top;
            if(top<=bottom){
            for(i=left;i<=right;i++){
                v.push_back(matrix[j][i]);
                // cout<<a[j][i]<<" ";
            }
            top++;
            j=right;}
            if(left<=right){
            for(i=top;i<=bottom;i++){
                v.push_back(matrix[i][j]);
                // cout<<a[i][j]<<" ";
            }
    //		break;
            right--;
            j=bottom;}
            if(top<=bottom){
                for(i=right;i>=left;i--){
                    v.push_back(matrix[j][i]);
                    // cout<<a[j][i]<<" ";
                }
                bottom--;
                j=left;
            }
            if(left<=right){
                for(i=bottom;i>=top;i--){
                    v.push_back(matrix[i][j]);
                    // cout<<a[i][j]<<" ";
                }
                left++;
            }
        }
        return v;
    }
};