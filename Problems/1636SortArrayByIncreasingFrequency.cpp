class Solution {
public:
    void display(map<int,int>m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        cout<<"\n";
        return;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    int get(int x,unordered_map<int,int>&visited,map<int,int>m){
        for(auto a:m){
            if(a.second==x){
                if(visited[a.first]==0){
                    visited[a.first]=1;
                    return a.first;
                }
            }
        }
        return 0;
    }

    vector<int> frequencySort(vector<int>& nums) {
        vector<int>v;
        vector<int>t;
        map<int,int>m;
        for(auto x: nums){
            ++m[x];
        }
        // display(m);
        for(auto x:m){
            t.push_back(x.second);
        }
        sort(t.begin(),t.end(),greater<int>());
        // display(t);
        unordered_map<int,int>visited;
        for(auto x:t){
            int a = get(x,visited,m);
            cout<<a<<" ";
            for(int i=0;i<x;i++){
                v.push_back(a);
            }
        }
        // display(t);
        reverse(v.begin(),v.end());
        return v;
    }
};
