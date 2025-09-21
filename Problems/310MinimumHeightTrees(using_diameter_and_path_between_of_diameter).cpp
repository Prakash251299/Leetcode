class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    
    void getPath(unordered_map<int,vector<int>>&m,int node,int h,int &maxh,int &val,int &found,vector<int>&path,int parent){
        if(node==val){
            found=1;
            path.push_back(node);
            return;
        }
        if(h>maxh){
            maxh=h;
            //val=node;
        }
        for(auto x:m[node]){
            if(x==parent)continue;
            if(found==1){break;}
            getPath(m,x,h+1,maxh,val,found,path,node);
        }
        if(found)
        path.push_back(node);
        return;
    }
    void traverse(unordered_map<int,vector<int>>&m,int node,int h,int &maxh,int &val,vector<int>&visited){
        if(h>maxh){
            maxh=h;
            val=node;
        }
        for(auto x:m[node]){
            if(visited[x])continue;
            visited[x]=1;
            traverse(m,x,h+1,maxh,val,visited);
        }
        return;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        queue<int>q;
        vector<int>visited(n+1,0);
        unordered_map<int,vector<int>>m;
        vector<int>counter(n+1,0);
        for(auto x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
            counter[x[0]]++;
            counter[x[1]]++;
        }
        int h=0,maxh=0,val=0;
        visited[0]=1;
        traverse(m,0,h,maxh,val,visited);
        //cout<<maxh<<" "<<val<<"\n";
        h=0;maxh=0;
        int val2=val;
        vector<int>visited2(n+1,0);
        visited2[val]=1;
        traverse(m,val,h,maxh,val2,visited2);
        //cout<<maxh<<" "<<val2<<"\n";
        int found=0;
        vector<int>path;
        //cout<<val<<" "<<val2<<"\n";
        h=0;maxh=0;
        getPath(m,val,h,maxh,val2,found,path,-1);
        //display(path);
        if(path.size()%2==0){
            return {path[path.size()/2-1],path[path.size()/2]};
        }
        return {path[path.size()/2]};
    }
};
