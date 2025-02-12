class Solution {
public:
    void display(unordered_map<int,vector<int>>m){
        for(auto x:m){
            cout<<x.first<<": ";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    void display(vector<int>v){
        cout<<"visited:  ";
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        vector<int>v;
        queue<int>q;
        int min = pow(10,5);
        int c = 0;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        // display(m);
        int flag = 0;
        for(int i=0;i<n;i++){
            queue<int>h; // for height
            vector<int>visited(n,0);
            // visited.clear();
            // cout<<"hi"<<"\n";
            c=0;
            q.push(i);
            h.push(0);
            visited[i] = 1;
            while(!q.empty()){
                // display(visited);
                flag = 0;
                // cout<<q.front()<<" ";
                if(m[q.front()].size()!=0){
                    // cout<<"inside"<<"\n";
                    for(auto x:m[q.front()]){
                        if(visited[x]!=1){
                            q.push(x);
                            h.push(h.front()+1);
                            visited[x] = 1;
                            // flag = 1;
                        }
                    }
                    // if(flag==1){                        
                    //     c++;
                    // }
                }
                c = h.back();
                h.pop();
                q.pop();
            }
            // cout<<"\n";
            // c = h.back();
            // h.erase();
            if(c<min){
                // cout<<"min: "<<c<<"\n";
                v.clear();
                v.push_back(i);
                min = c;
            }else{
                if(c==min){
                    // cout<<"min: "<<c<<"\n";
                    v.push_back(i);
                }
            }
        }
        return v;
    }
};
