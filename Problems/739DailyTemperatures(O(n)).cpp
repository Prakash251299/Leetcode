class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>a;
        vector<int>v=temperatures;
        vector<int>del(v.size(),0);
        for(int i=v.size()-1;i>=0;i--){
            if(a.empty()){
                a.push_back(i);
                v[i] = 0;
            }else{
                while(!a.empty() && temperatures[i]>=temperatures[a[a.size()-1]]){
                    a.pop_back();
                }
                if(a.empty()){
                    v[i] = 0;
                }else{
                    v[i] = a[a.size()-1]-i;
                }
                    a.push_back(i);
            }
        }
        return v;
    }
};
