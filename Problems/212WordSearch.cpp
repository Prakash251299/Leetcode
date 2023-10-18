// This is solution for word search but it is showing time limit exceeded

class Solution {
public:
    int checkVisited(vector<vector<int>>& visited,int i, int j){
        // for(int i=0;i<visited.size();i++){
        //     for(int j=0;j<visited[0].size();j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if(visited[i][j]==1){
            return 1;
        }
        return 0;
    }
    
    void search(vector<vector<char>>& board, vector<string>& words,int i,int j,int k,int l,vector<vector<int>>& visited,vector<string>&res,int *found){
        // if(l>=words[k].size()){
        //     res.push_back(words[k]);
        //     *found=1;
        //     return;
        // }
        if(checkVisited(visited,i,j)){
            return;
        }
        if(board[i][j]==words[k][l]){
            visited[i][j]=1;
            if(l+1>=words[k].size()){
                res.push_back(words[k]);
                checkVisited(visited,i,j);
                *found=1;
                visited[i][j]=0;
                return;
            }
        }else{
            return;
        }
        
        if(*found==0 and i-1>=0){
            // visited[i-1][j]=1;
            search(board,words,i-1,j,k,l+1,visited,res,found);
            // visited[i-1][j]=0;
            // visited[i][j]=0;
        }
        if(*found==0 and j-1>=0){
            // visited[i][j-1]=1;
            search(board,words,i,j-1,k,l+1,visited,res,found);
            // visited[i][j-1]=0;
            // visited[i][j]=0;
        }
        if(*found==0 and i+1<board.size()){
            // visited[i+1][j]=1;
            search(board,words,i+1,j,k,l+1,visited,res,found);
            // visited[i+1][j]=0;
            // visited[i][j]=0;
        }
        if(*found==0 and j+1<board[0].size()){
            // visited[i][j+1]=1;
            search(board,words,i,j+1,k,l+1,visited,res,found);
            // visited[i][j+1]=0;
            // visited[i][j]=0;
        }
        visited[i][j]=0;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int i=0,j=0,k=0,l=0;
        vector<string>res;
        vector<vector<int>>visited;
        vector<int>temp;
        for(i=0;i<board.size();i++){
            for(j=0;j<board[0].size();j++){
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
        for(k=0;k<words.size();k++){
            int a = 0;
            int *found=&a;
            // for(int m=0;m<board.size();m++){
            //     for(int n=0;n<board[0].size();n++){
            //         visited[m][n]=0;
            //     }
            // }
            // cout<<words[k]<<":\n";
            for(i=0;i<board.size();i++){
                if(*found==1){
                    break;
                }
                for(j=0;j<board[0].size();j++){
                    if(*found==1){
                        break;
                    }
                    visited[i][j]=0;
                    // if(board[i][j]==words[k][l]){
                    //     cout<<board[i][j]<<endl;
                        // visited.push_back({i,j});
                    search(board,words,i,j,k,l,visited,res,found);
                    // for(int m=0;m<board.size();m++){
                    //     for(int n=0;n<board[0].size();n++){
                    //         visited[m][n]=0;
                    //     }
                    // }
                    // visited[i][j]=0;
                        // visited.pop_back();
                    // }

                    // cout<<i<<" "<<j<<":"<<board[i][j]<<endl;
                }
            }
        }
        // search(board,words,0,0);
        // cout<<board;
        return res;
    }
};