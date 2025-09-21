class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        unordered_map<int,vector<int>>m;
        vector<int>v;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int>count;
        queue<int>leaf;


        for(auto x:m){
            count[x.first] = x.second.size();
            if(x.second.size()==1){
                leaf.push(x.first);
            }
        }
        while(1){
            if(n<=2){
                break;
            }
            int leafSize=leaf.size();
            n-=leafSize;
            int i=0;
            while(i<leafSize){
                for(auto x:m[leaf.front()]){
                    --count[x];
                    if(count[x]==1){
                        leaf.push(x);
                    }
                }
                leaf.pop();
                i++;
            }
        }
        while(!leaf.empty()){
            v.push_back(leaf.front());
            leaf.pop();
        }
        return v;
    }
};
