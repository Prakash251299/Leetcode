class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq){
        while(!pq.empty()){
            for(auto x:pq.top()){
                cout<<x<<" ";
            }
            cout<<", ";
            pq.pop();
        }
        cout<<"\n";
    }
    int getVal(vector<vector<int>>&v,priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>&pq,vector<vector<int>>&visited,int i,int j,int i1,int j1){
        int res=0;
        if(i>=0&&i<v.size()&&j>=0&&j<v[0].size()){
            if(visited[i][j]==0){
                visited[i][j]=1;
                if(v[i][j]<v[i1][j1]){
                    pq.push({v[i1][j1],i,j});
                    res+=v[i1][j1]-v[i][j];
                    v[i][j]=v[i1][j1];
                }else{
                    pq.push({v[i][j],i,j});
                }
            }
        }
        return res;
    }
    int nearbyWall(vector<vector<int>>&v,priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>&pq,vector<vector<int>>&visited,int i,int j){
        int res=0;
        res+= getVal(v,pq,visited,i+1,j,i,j);
        res+= getVal(v,pq,visited,i,j+1,i,j);
        res+= getVal(v,pq,visited,i-1,j,i,j);
        res+= getVal(v,pq,visited,i,j-1,i,j);
        return res;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>>v=heightMap;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>visited(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<v.size();i++){
            pq.push({v[i][0],i,0});
            visited[i][0]=1;
        }
        for(int j=1;j<v[0].size();j++){
            pq.push({v[0][j],0,j});
            visited[0][j]=1;
        }
        for(int i=1;i<v.size();i++){
            int j=v[0].size()-1;
            pq.push({v[i][j],i,j});
            visited[i][j]=1;
        }
        for(int j=1;j<v[0].size()-1;j++){
            int i=v.size()-1;
            pq.push({v[i][j],i,j});
            visited[i][j]=1;
        }
        
        int res=0;
        while(!pq.empty()){
            int val=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
                if(!pq.empty())
                    res+=nearbyWall(v,pq,visited,i,j);
        }
        return res;
    }
};
