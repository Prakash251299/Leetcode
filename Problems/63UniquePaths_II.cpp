class Solution {
public:
    void display(vector<vector<int>>&grid){
        for(auto x:grid){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)grid[i][j]=-1;
            }
        }
        grid[0][0]=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-1){
                    continue;
                }
                if(i-1>=0){
                    if(grid[i-1][j]!=-1)
                    grid[i][j]+=grid[i-1][j];
                }
                if(j-1>=0){
                    if(grid[i][j-1]!=-1)
                    grid[i][j]+=grid[i][j-1];
                }
            }
        }

        //display(grid);
        if(grid[grid.size()-1][grid[0].size()-1]==-1)return 0;
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
