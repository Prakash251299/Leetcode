class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void traverse(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited){
        if(i<0||j<0)return;
        if(i>=grid.size()||j>=grid[0].size())return;
        if(visited[i][j]==1||grid[i][j]=='0'){
            return;
        }
        visited[i][j]=1;
        traverse(grid,i+1,j,visited);
        traverse(grid,i,j+1,visited);
        traverse(grid,i-1,j,visited);
        traverse(grid,i,j-1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int n=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==1)continue;
                if(grid[i][j]=='0')continue;
                traverse(grid,i,j,visited);
                n++;
            }
        }
        return n;
    }
};
