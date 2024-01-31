class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>a;
        vector<int>v=temperatures;
        // vector<int>temperatures=temperatures;
        vector<int>del(v.size(),0);
        for(int i=v.size()-1;i>=0;i--){
            if(a.empty()){
                a.push_back(i);
                v[i] = 0;
            }else{
                for(int j=a.size()-1;j>=0;j--){
                    //
                    if(v[i]>=temperatures[a[j]]){
                        del[i] = del[i] + del[a[j]];
                        ++del[i];
                        a.pop_back();
                    }else{
                        a.push_back(i);
                        v[i] = del[i]+1;
                        break;
                    }
                }
                if(a.empty()){
                    a.push_back(i);
                    v[i] = 0;
                }
            }
        }
        display(del);
        return v;
    }
};
