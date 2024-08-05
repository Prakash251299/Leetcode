class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        vector<int>t;
        t.push_back(0);
        traverse(graph,v,t,0);
        // For reaching to the end from every node
        // for(int i=0;i<graph.size();i++){
        //     t.push_back(i);
        //     traverse(graph,v,t,i);
        //     t.pop_back();
        // }
        return v;
    }
    void traverse(vector<vector<int>>&graph, vector<vector<int>>&v,vector<int>t,int i){
        for(int j=0;j<graph[i].size();j++){
            t.push_back(graph[i][j]);
            traverse(graph,v,t,graph[i][j]);
            t.pop_back();
        }
        if(t.size()==0){
            return;
        }
        if(t[t.size()-1]==graph.size()-1){
            v.push_back(t);
        }
        return;

    }
};
