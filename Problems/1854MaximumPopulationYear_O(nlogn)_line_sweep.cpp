class Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            cout<<x[0]<<":"<<x[1]<<"\n";
        }
        cout<<"\n";
    }
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>>v;
        for(auto x:logs){
            v.push_back({x[0],+1});
            v.push_back({x[1],-1});
        }
        sort(v.begin(),v.end());
        // display(v);
        int sum=0,y=0,m=0;
        for(auto x:v){
            sum+=x[1];
            if(sum>m){
                m=sum;
                y=x[0];
            }
        }
        return y;
    }
};
