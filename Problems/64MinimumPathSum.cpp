class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                // cout<<grid[i][j]<<" ";
                int a=50000,b=50000;
                if(i+1<grid.size()){
                    a = grid[i+1][j];
                }
                if(j+1<grid[0].size()){
                    b = grid[i][j+1];
                }
                if(i+1>=grid.size() && j+1>=grid[0].size()){
                    a=0;
                }
                a = min(a,b);
                grid[i][j] = grid[i][j]+a;
            }
            // cout<<"\n";
        }
        return grid[0][0];
    }
};
