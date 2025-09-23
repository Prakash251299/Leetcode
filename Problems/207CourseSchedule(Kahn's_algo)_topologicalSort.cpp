class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
            ++indegree[x[0]];
        }
        //cout<<"indegree: ";
        //display(indegree);
        queue<int>q;
        vector<int>res;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        //cout<<"initial queue: ";
        //display(res);
        while(!q.empty()){
            //cout<<q.front()<<": \n";
            for(auto x:adj[q.front()]){
                //cout<<x<<" ";
                if(indegree[x]==1){
                    q.push(x);
                    res.push_back(x);
                }
                indegree[x]=max(0,indegree[x]-1);
            }
            //cout<<"\n";
            q.pop();
        }
        for(auto x:indegree){
            if(x>0){
                return false;
                return {};
            }
        }
        //for()
        return true;
    }
};
