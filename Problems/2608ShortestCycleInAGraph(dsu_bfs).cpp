class Solution {
public:
    void display(set<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int findParent(int a, vector<int>&parent){
    if(parent[a]==a){
        return a;
    }
    parent[a]=findParent(parent[a],parent);
    return parent[a];
}
void dsuUnion(int a,int b,vector<int>&parent,vector<int>&size,set<int>&loopend){
    int p1=findParent(a,parent);
    int p2=findParent(b,parent);
    if(p1==p2){
        loopend.insert(a);return;
    }
    if(size[p1]>=size[p2]){
        parent[p2]=p1;
        size[p1]=size[p1]+size[p2];
        return;
    }
    if(size[p1]<size[p2]){
        parent[p1]=p2;
        size[p2]=size[p1]+size[p2];
    }
}
    
    void minCycle(int n,queue<int>q,vector<vector<int>>&adj,int &ans){
        vector<int>visited(n+1,0);
        vector<int>dist(n+1,0);
        //visited[q.front()]=1;
        vector<int>parent(n+1,-1);
        //parent[q.front()]=q.front();
        int h=0,flag=0;
        while(!q.empty()){
          //  cout<<q.front()<<" ";
            int i=0,qsz=q.size();
            h++;
            while(i<qsz){
                for(auto x:adj[q.front()]){
                    if(parent[q.front()]==x)continue;
                    
                    if(visited[x]==1){
                        ans=min(ans,dist[x]+dist[q.front()]+1);
                       // cout<<"\n("<<x<<")\n";
                        flag=1;
                        continue;
                    }
                    visited[x]=1;
                    q.push(x);
                    //h++;
                    dist[x]=h;
                    parent[x]=q.front();
                }
                q.pop();
                i++;
            }
            //h++;
            if(flag==1){
               //return;
            }
            //q.pop();
        }
        //cout<<q.size()<<"qsize\n";
        return;
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>parent(n+1,0);
        vector<int>size(n+1,1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        set<int>loopend;
        for(auto x:edges){
            dsuUnion(x[0],x[1],parent,size,loopend);
        }
        if(loopend.size()==0)return -1;
        //display(loopend);
        //unordered_map<int,vector<int>>adj;
        vector<vector<int>>adj(n+1);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=INT_MAX;
        //queue<int>q;
        //q.push(loopend.first);
        int x=0;
        for(auto val:loopend){
            //x=val;break;
        //}
            vector<int>visited(n+1,0);
            queue<int>q;
            q.push(val);
            visited[val]=1;
            //cout<<"\n";
            minCycle(n,q,adj,ans);
            //q.clear();
            
        }
        return ans;
    }
};
