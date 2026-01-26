class Solution {
public:
    void display(unordered_map<int,int>& parent){
        for(auto x:parent){
            cout<<x.first<<": "<<x.second<<"\n";
        }
        cout<<"\n";
    }

    void unionFun(unordered_map<int,int>& parent, unordered_map<int,int>& sz, int a, int b){
        int pa = findParent(parent,a);
        int pb = findParent(parent,b);
        if(pa==pb){
            return;
        }
        if(sz[pa]<=sz[pb]){
            ++sz[pb];
            parent[pa]=pb;
            return;
        }
        parent[pb]=pa;
        ++sz[pa];
        return;
    }
    int findParent(unordered_map<int,int>& parent, int a){
        if(parent[a]==a||parent[a]==0){return a;}
        return parent[a] = findParent(parent,parent[a]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>v=isConnected;
        unordered_map<int,int>sz;
        unordered_map<int,int>parent;
        for(int i=1;i<=v.size();i++){
            for(int j=1;j<=v[0].size();j++){
                if(v[i-1][j-1]==1){
                    if(parent[i]==0){
                        parent[i]=i;
                        sz[i]=1;
                    }
                    if(parent[j]==0){
                        parent[j]=j;
                        sz[j]=1;
                    }
                    unionFun(parent,sz,i,j);
                }
            }
        }
        for(auto x:parent){
            findParent(parent,x.first);
        }
        int c=0;
        unordered_map<int,int>visited;
        for(auto x:parent){
            if(x.second!=0){
                if(!visited[x.second]){
                    visited[x.second]=1;
                    c++;
                }
            }
        }
        return c;
    }
};
