class Solution {
public:
    float findDistance(int x1,int y1,int x2, int y2){
        return sqrt((long long)(x1-x2)*(x1-x2)+(long long)(y1-y2)*(y1-y2));
    }

    //void expand(unordered_map<int,vector<int>>&m,set<int>&s,int i,vector<int>&visited){
    void expand(vector<vector<int>>&m,set<int>&s,int i,vector<int>&visited){
        for(int j=0;j<m[i].size();j++){
            if(visited[m[i][j]]==1){
                continue;
            }
            visited[m[i][j]]=1;
            s.insert(m[i][j]);
            expand(m,s,m[i][j],visited);
        }
        return;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //unordered_map<int,vector<int>>m;
        vector<vector<int>>m(bombs.size());
        for(int i=0;i<bombs.size();i++){
            for(int j=0;j<bombs.size();j++){
                if(i==j){
                    continue;
                }
                if(findDistance(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1])<=bombs[i][2]){
                    m[i].push_back(j);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<bombs.size();i++){
            set<int>s;
            vector<int>visited(bombs.size()+1);
            visited[i]=1;
            s.insert(i);
            expand(m,s,i,visited);
            if(s.size()>maxi){
                maxi=s.size();
            }
        }
        return maxi;
    }
};
