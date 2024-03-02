class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    bool validBox(vector<vector<char>>& v, int r, int c){
        vector<int> visited(10,0);
        int a = r%3;
        r = r - a;
        a = c%3;
        c = c - a;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                // cout<<v[i][j]<<" ";
                // display(visited);
                if(v[i][j]!='.'){
                    if(visited[v[i][j]-'0']==1){
                        return false;
                    }else{
                        visited[v[i][j]-'0']=1;
                        // cout<<v[i][j]-'0'<<" ";
                        // cout<<v[i][j]<<" ";
                    }
                }
            }
        }
        return true;
    }

    void initialize(vector<int>&v){
        for(int i=0;i<v.size();i++){
            v[i]=0;
        }
        return;
    }
    bool validRow(vector<vector<char>>& v){
        vector<int>visited(10,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(v[i][j]!='.'){
                    if(visited[v[i][j]-'0']==1){
                        cout<<"hi";
                        return false;
                    }else{
                        visited[v[i][j]-'0']=1;
                        // cout<<v[i][j]-'0'<<" ";
                        // cout<<v[i][j]<<" ";
                    }
                }
            }
            // visited.clear();
            initialize(visited);
        }
        return true;
    }

    bool validColumn(vector<vector<char>>& v){
        vector<int> visited(10,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(v[j][i]!='.'){
                    if(visited[v[j][i]-'0']==1){
                        return false;
                    }else{
                        visited[v[j][i]-'0']=1;
                        // cout<<v[i][j]-'0'<<" ";
                        // cout<<v[i][j]<<" ";
                    }
                }
            }
            // visited.clear();
            initialize(visited);
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int i=0,j=0;
        while(true){
            if(j>6){
                break;
            }
            if(!validBox(board,i,j)){
                return false;
            }
            i = i + 3;
            if(i>6){
                i=0;
                j+=3;
            }
        }
        if(!validRow(board)){
            return false;
        }
        if(!validColumn(board)){
            return false;
        }
        return true;
    }
};
