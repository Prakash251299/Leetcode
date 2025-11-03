class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x: v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(queue<vector<int>>q){
        while(!q.empty()){
            cout<<q.front()[0]<<","<<q.front()[1]<<"\n";
            q.pop();
        }
        cout<<"\n";
    }
    int checkValidity(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n){
            return 0;
        }
        return 1;
    }
    int traceNearby(vector<vector<int>>&grid,vector<int>topVal,int &m,int &n,vector<vector<int>>&visited,queue<vector<int>>&q,int &count){
        int i=topVal[0],j=topVal[1];
        int change=0;
        if(checkValidity(i-1,j,m,n)){
            if(grid[i-1][j]==1){
                grid[i-1][j]=2;
                change=1;
                q.push({i-1,j});
            }
        }
        if(checkValidity(i+1,j,m,n)){
            if(grid[i+1][j]==1){
                q.push({i+1,j});
                grid[i+1][j]=2;
                change=1;
            }
        }
        if(checkValidity(i,j-1,m,n)){
            if(grid[i][j-1]==1){
                grid[i][j-1]=2;
                change=1;
                q.push({i,j-1});
            }
        }
        if(checkValidity(i,j+1,m,n)){
            if(grid[i][j+1]==1){
                grid[i][j+1]=2;
                change=1;
                q.push({i,j+1});
            }
        }
        return change;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    queue<vector<int>>q;
    int count=0,found=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    int res=0;
    while(!q.empty()){
        int tempSz=q.size();
        int nextGo=0;
        for(int i=0;i<tempSz;i++){
                nextGo=max(traceNearby(grid,q.front(),m,n,visited,q,count),nextGo);
            q.pop();
        }
        if(nextGo==1){
            res++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return res;
    }
};
