class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        unordered_map<int,vector<int>>m;
        vector<int>v;
        vector<int>visited(n,0);
        int height=0;
        
        int min = pow(10,5);
        int endLeaf = 0;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        // display(m);
        unordered_map<int,int>count;
        queue<int>leaf;


        for(auto x:m){
            count[x.first] = x.second.size();
            if(x.second.size()==1){
                leaf.push(x.first);
            //     visited[x.first] = 1;
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
                --count[leaf.front()];
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
        // display(leaf);
        while(!leaf.empty()){
            v.push_back(leaf.front());
            leaf.pop();
        }
        return v;
    }
};
