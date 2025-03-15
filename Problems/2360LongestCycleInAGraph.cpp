class Solution {
public:
    int longestCycle(vector<int>& edges) {
        unordered_map<int,int>visited={};
        int maxx = 0,c = 0;
        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1){
                visited[i]=1;
                continue;
            }
            if(visited[i]==1){
                continue;
            }
            int j=i;
            visited[j]=1;
            c=2;
            unordered_map<int,int>currVisited={};
            currVisited[j]=1;
            while(1){
                if(edges[j]==-1){
                    visited[j]=1;
                    // cout<<"yes";
                    break;
                }
                if(currVisited[edges[j]]>0){
                    int t = c-currVisited[edges[j]];
                    visited[edges[j]] = 1;
                    if(t>maxx){
                        maxx = t;
                    }
                    break;
                }
                if(visited[edges[j]]==1){break;}
                currVisited[edges[j]] = c;
                visited[edges[j]]=1;
                j = edges[j];
                c++;
                // cout<<"y";
            }
            // break;
        }
        if(maxx == 0){
            return -1;
        }
        return maxx;
        
    }
};
