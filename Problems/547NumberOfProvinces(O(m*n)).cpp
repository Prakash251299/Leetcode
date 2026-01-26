class Solution {
public:
    void display(unordered_map<int,vector<int>>&m){
        for(auto x:m){
            cout<<x.first<<": ";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void traverse(unordered_map<int,vector<int>>&m,unordered_map<int,int>&visited,int i){
        if(visited[i]==1){
            return;
        }
        visited[i]=1;
        for(auto x:m[i]){
            traverse(m,visited,x);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c=0;
        vector<vector<int>>v=isConnected;
        unordered_map<int,vector<int>>m;
        for(int i=1;i<=v.size();i++){
            for(int j=1;j<=v[0].size();j++){
                if(v[i-1][j-1]==1)
                    m[i].push_back(j);
            }
        }
        //display(m);
        unordered_map<int,int>visited;
        for(int i=1;i<=v.size();i++){
            if(visited[i]!=1){
                c++;
                traverse(m,visited,i);
            }
        }
        return c;
    }
};
