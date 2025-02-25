class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    void display(unordered_map<int,int>m){
        for(auto x:m){
            cout<<x.first<<": "<<x.second<<"\n";
        }
        cout<<"\n";
    }

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

    void getProfit(int curr,int c,vector<int>&amount,unordered_map<int,int>&time,int &sum,int bob){
        int t = time[curr];
        if(t==0 && bob==curr){
            return;
        }
        if(t>c || t==0){
            sum+=amount[curr];
            // if(sum>max){
            //     max = sum;
            // }
            return;
        }
        if(t==c){
            sum+=(amount[curr]/2);
            // if(sum>max){
            //     max = sum;
            // }
            return;
        }
        return;
    }

    int max = -100000;
    void traverse(unordered_map<int,vector<int>>&m,vector<int>&amount,unordered_map<int,int>&time,int c,int curr,int sum,int bob,unordered_map<int,int>&visited){
        getProfit(curr,c,amount,time,sum,bob);
        // if(m[curr].size()==1){
        //     if(sum>max){
        //         max = sum;
        //     }
        // }
        // cout<<"curr: "<<curr<<" ";
        // cout<<"size: "<<m[curr].size()<<"\n";
        for(auto x:m[curr]){
            if(visited[x]!=1){
                visited[x]=1;
                traverse(m,amount,time,c+1,x,sum,bob,visited);
            }else{
                if(m[curr].size()==1){
                    if(sum>max){
                        max = sum;
                    }
                }
            }
        }
        return;
        // queue<int>q;
        // q.push(0);
        // int c = 0, res=0;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,vector<int>>m;
        for(auto x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        // display(m);
        queue<int>q;
        unordered_map<int,int>parent;
        vector<int>v;
        unordered_map<int,int>pathWithTime;
        q.push(bob);
        parent[bob] = bob;
        int c=0;
        while(!q.empty()){
            for(auto val:m[q.front()]){
                // parent[val] = q.front();
                if(val==0){
                    // c++;
                    // cout<<"count: "<<c<<"\n";
                    parent[val] = q.front();
                    v.push_back(0);
                    // pathWithTime[0] = c;
                    // c--;
                    int a = 0;
                    while(a!=bob){
                        a = parent[a];
                        v.push_back(a);
                        // pathWithTime[a] = c;
                        // c--;
                    }
                    while(!q.empty()){
                        q.pop();
                    }
                    break;
                }
                if(val!=parent[q.front()]){
                    q.push(val);
                    parent[val] = q.front();
                }
            }
            if(!q.empty()){
                q.pop();
            }
            // c++;
        }
        // c=0;
        for(int k = v.size()-1;k>=0;k--){
            pathWithTime[v[k]] = c;
            c++;
        }
        // cout<<"count: "<<c<<"\n";
        // display(v);
        // display(pathWithTime);
        c=0;
        unordered_map<int,int>visited;
        visited[0]=1;
        traverse(m,amount,pathWithTime,c,0,0,bob,visited);
        return max;
    }

};
