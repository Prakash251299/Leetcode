class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    long long mostPoints(vector<vector<int>>& questions) {
        long long max=0;
        vector<long long>v(questions.size(),0);
        for(int i=v.size()-1;i>=0;i--){
            int t = i+questions[i][1]+1;
            if(t>=questions.size()){
                v[i] = questions[i][0];
            }else{
                v[i] = questions[i][0]+v[t];
            }
            if(v[i]>max){
                max=v[i];
            }else{
                v[i] = max;
            }
        }
        // display(v);

        return max;
    }
};
