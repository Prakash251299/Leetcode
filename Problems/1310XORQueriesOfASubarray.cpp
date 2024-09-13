class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        return;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res;
        vector<int>store(arr.size(),0);
        store[0]=arr[0];
        int i=1;
        for(;i<arr.size();i++){
            store[i] = store[i-1]^arr[i];
        }
        // display(store);
        for(i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                int t = store[queries[i][1]];
                res.push_back(t);
                continue;
            }
            int t = store[queries[i][0]-1]^store[queries[i][1]];
            res.push_back(t);
        }
        return res;
    }
};
