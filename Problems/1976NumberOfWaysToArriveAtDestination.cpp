class Solution {
public:
    void display(vector<long long>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(unordered_map<int, vector<vector<int>>> m) {
        for (auto x : m) {
            cout << x.first << ":";
            // <<m[x.first].size()<<" ";
            for (int i = 0; i < m[x.first].size(); i++) {
                cout << m[x.first][i][0] << "-" << m[x.first][i][1] << " ";
            }
            cout << endl;
        }
    }

    // void dis(vector<int> v) {
    //     for (auto x : v) {
    //         cout << x << " ";
    //     }
    // }

    void traverse(vector<vector<int>>& roads, int i, int n,
                  unordered_map<int, vector<vector<int>>> m,
                  unordered_map<int, int> v, long sum, long& min, long& c) {
        if (sum > min) {
            return;
        }
        for (auto x : m[i]) {
            if (v[x[0]] == 1) {
                continue;
            }
            v[x[0]] = 1;
            sum += x[1];
            if (x[0] == n) {
                if (min == sum) {
                    c++;
                }
                if (min > sum) {
                    min = sum;
                    c = 1;
                }
            }
            // cout<<x[0]<<":"<<x[1]<<"\n";
            traverse(roads, x[0], n, m, v, sum, min, c);
            sum -= x[1];
            v[x[0]] = 0;
            // if()
            // cout<<m[i].size();
            // for(int j=0;j<x.size();j++){
            //     cout<<x[j][0]<<" ";
            // }
        }
        return;
    }

    void showQ(priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>p){
        while(!p.empty()){
            for(auto x:p.top()){
                cout<<x<<" ";
            }
            p.pop();
        }
        cout<<"\n";
        return;
    }

    void traversal(unordered_map<int,vector<vector<int>>>m,priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq,vector<long long>&w,vector<long long>&t){
        while(1){
            if(pq.empty()){
                return;
            }
            // showQ(pq);
            vector<long long> temp = pq.top();
            pq.pop();
            // cout<<t[0]<<" "<<temp[1];
            // display(m);
            // cout<<m[];
            for(auto x:m[temp[1]]){
                long long d = temp[0]+x[1];
                if(d<t[x[0]]){
                    pq.push({d,x[0]});
                    w[x[0]]=w[temp[1]];
                    t[x[0]]=d;
                }else{
                    if(d>t[x[0]]){
                        continue;
                    }else{
                        w[x[0]]= (w[x[0]]+w[temp[1]]) % 1000000007;
                        // w[x[0]]%=1000000007;
                    }
                }
                // w[x]+=w[temp[1]];
                // cout<<x[0]<<" "<<x[1];
            }
            // cout<<"ways"<<": ";
            // display(w);
            // cout<<"time"<<": ";
            // display(t
        }
        return;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        // Arranging all data
        unordered_map<int,vector<vector<int>>>m;
        vector<int>v;
        for(int i=0;i<roads.size();i++){
            v.push_back(roads[i][1]);
            v.push_back(roads[i][2]);
            m[roads[i][0]].push_back(v);
            v.clear();
            v.push_back(roads[i][0]);
            v.push_back(roads[i][2]);
            m[roads[i][1]].push_back(v);
            v.clear();
        }
        // display(m);
        // Working on the arranged data
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        pq.push({0,0});
        vector<long long>ways(n,0);
        long long t = 1000000007;
        long long t1 = pow(10,13);
        vector<long long>time(n,t1);
        ways[0]=1;
        time[0]=0;
        // display(time);
        traversal(m,pq,ways,time);
        // showQ(pq);
        // display(ways);

        // pq.push({1,1});
        // pq.push({2,2});
        // pq.push({1,3});
        // pq.push({2,4});
        // pq.push({3,5});
        // pq.push({4,7});
        // cout<<pq.top().size();
        // showQ(pq);
        return ways[n-1]%t;
    }
    
};
