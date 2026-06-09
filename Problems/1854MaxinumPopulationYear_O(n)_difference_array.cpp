class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>v(102,0);
        for(auto x:logs){
            int i=x[0]-1950;
            int j=x[1]-1950;
            v[i]+=1;
            v[j]-=1;
        }
        //display(v);
        int m=0,y=0,sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum>m){
                m=sum;
                y=i+1950;
            }
        }
        return y;
    }
};
