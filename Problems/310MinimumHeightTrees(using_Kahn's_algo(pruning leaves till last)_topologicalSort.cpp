class Solution {
public:
    void display(queue<int>q){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<"\n";
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
        for(auto x:m){
            if(x.second.size()==1){
                q.push(x.first);
                //visited[x.first]=1;
                //--counter[x.first];
            }
        }
        //display(q);
        vector<int>res;
        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                //cout<<q.front()<<" ";
                if(sz<=2){
                    res.push_back(q.front());
                }
                counter[q.front()]=max(0,counter[q.front()]-1);
                for(auto x:m[q.front()]){
                    counter[x]=max(0,counter[x]-1);
                    if(counter[x]==1){
                        q.push(x);
                    }
                }
                q.pop();
            }
            if(!q.empty()){
                res.clear();
            }
        }
        
        return res;
    }
};
