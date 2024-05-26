class Solution {
public:
    bool sameBox(vector<vector<char>>& v, int r, int c,vector<int>visited){
        int a = r%3;
        r = r - a;
        a = c%3;
        c = c - a;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(v[r][c]!='.'){
                    if(visited[v[r][c]]==1){
                        return false;
                    }else{
                        visited[v[r][c]]==1;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> visited(9,0);
        if(!sameBox(board,0,0,visited)){
            return false;
        }
        return true;
    }
};
