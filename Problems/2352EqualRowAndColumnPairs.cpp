class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int i=0,j=0,flag=1,count=0,m=0,n=0,k=0,x=0,y=0;
        m = grid.size();
        n = grid[0].size();
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                for(k=0;k<n;k++){
                    if(grid[k][j]!=grid[i][k]){
                        flag = 0;
                        break;
                    }else{
                        flag = 1;
                    }
                    // cout<<grid[k][j]<<" "<<grid[i][k]<<endl;
                }
                if(flag==1){
                    count++;
                    // flag = 1;
                }
            }
        }
        return count;
    }
};