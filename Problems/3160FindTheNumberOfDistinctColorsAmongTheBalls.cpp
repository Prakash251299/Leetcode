class Solution {
public:
    void display(unordered_map<int,int>m){
        for(auto x:m){
            cout<<x.first<<": "<<x.second;
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>o; // object
        unordered_map<int,int>c; // colour
        vector<int> v;
        int count = 0;
        for(int i=0;i<queries.size();i++){
            if(o[queries[i][0]]==0){
                o[queries[i][0]] = queries[i][1];
                ++c[queries[i][1]];
            }else{
                --c[o[queries[i][0]]];
                if(c[o[queries[i][0]]]==0){
                    c.erase(o[queries[i][0]]);
                }
                o[queries[i][0]] = queries[i][1];
                ++c[queries[i][1]];
            }
            // display(c);
            v.push_back(c.size());
        }
        return v;
    }
};
