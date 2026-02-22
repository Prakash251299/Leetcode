class Solution {
public:
    void display(vector<vector<int>>& mat){
        for(auto x:mat){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int valid(vector<vector<int>>& mat,vector<vector<int>>& visited,int i, int j){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(visited[i][j]==2)return 0;
        return 1;
    }
    int traverse(vector<vector<int>>& mat, vector<vector<int>>& visited, vector<vector<int>>& value,int i, int j){
        int v1=0,v2=0,v3=0,v4=0;
        if(visited[i][j]==2){return 0;}
        if(valid(mat,visited,i-1,j)){
            if(mat[i-1][j]<mat[i][j]){
                if(visited[i-1][j]==1){
                    v1=value[i-1][j];
                }else{
                    visited[i][j]=2;
                    v1 = traverse(mat,visited,value,i-1,j);
                }
            }
        }
        if(valid(mat,visited,i,j+1)){
            if(mat[i][j+1]<mat[i][j]){
                if(visited[i][j+1]==1){
                    v2=value[i][j+1];
                }else{
                    visited[i][j]=2;
                    v2 = traverse(mat,visited,value,i,j+1);
                }
            }
        }
        if(valid(mat,visited,i+1,j)){
            if(mat[i+1][j]<mat[i][j]){
                if(visited[i+1][j]==1){
                    v3=value[i+1][j];
                }else{
                    visited[i][j]=2;
                    v3 = traverse(mat,visited,value,i+1,j);
                }
            }
        }
        if(valid(mat,visited,i,j-1)){
            if(mat[i][j-1]<mat[i][j]){
                if(visited[i][j-1]==1){
                    v4 = value[i][j-1];
                }else{
                    visited[i][j]=2;
                    v4 = traverse(mat,visited,value,i,j-1);
                }
            }
        }
        value[i][j]=value[i][j]+max(v1,max(v2,max(v3,v4)));
        visited[i][j]=1;
        return value[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>value(matrix.size(),vector<int>(matrix[0].size(),1));
        int res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(visited[i][j]==1)continue;
                int v = traverse(matrix,visited,value,i,j);
                visited[i][j]=1;
                if(value[i][j]>res){
                    res=value[i][j];
                }
            }
        }
        return res;
    }
};
