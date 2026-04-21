class Solution {
public:
    void allConn(int &st,unordered_map<int,vector<int>>&m,vector<int>&idg,queue<int>&q){
        for(auto x:m[st]){
            idg[x]--;
            if(idg[x]==0){
                q.push(x);
            }
        }
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre,vector<int>&res) {
        vector<int>idg(numCourses,0);
        queue<int>q;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<pre.size();i++){
            m[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<pre.size();i++){
            idg[pre[i][0]]++;
        }
        for(int i=0;i<idg.size();i++){
            if(idg[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            allConn(q.front(),m,idg,q);
            res.push_back(q.front());
            q.pop();
            c++;
        }
        if(c==numCourses)return true;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>res;
        bool noloop=canFinish(numCourses,pre,res);
        if(!noloop)return {};
        return res;
    }
};
