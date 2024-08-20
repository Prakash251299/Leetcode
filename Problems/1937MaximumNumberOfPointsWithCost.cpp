class Solution {
public:
    void display(vector<long long>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    long long max(long long a, long long b){
        if(a>b){
            return a;
        }
        return b;
    }
    vector<long long> get(vector<long long>v){
        vector<long long>t;
        for(int i=0;i<v.size();i++){
            if(i==0){
                t.push_back(v[i]);
                continue;
            }
            long long a = max(t[i-1]-1,v[i]);
            t.push_back(a);
        }
        // display(t);
        vector<long long>t2=t;
        for(int i=v.size()-1;i>=0;i--){
            if(i==v.size()-1){
                t2[t2.size()-1] = v[v.size()-1];
                continue;
            }
            long long a = max(t2[i+1]-1,v[i]);
            t2[i] = a;
        }
        // display(t2);
        for(int i=0;i<t.size();i++){
            t[i] = max(t[i],t2[i]);
        }
        // display(t);
        return t;
    }

    long long maxPoints(vector<vector<int>>& points) {
        vector<long long>v(points[0].size(),0);
        vector<long long>t;
        for(auto x:points[0]){
            t.push_back(x);
        }
        // points[0];
        // display(t);
        for(int i=0;i<points.size();i++){
            for(int k=0;k<points[i].size();k++){
                t[k] = points[i][k];
            }
            // t = points[i];
            for(int j=0;j<points[0].size();j++){
                t[j] = t[j] + v[j];
            }
            if(i==points.size()){
                break;
            }
            v = get(t);
            // display(v);
        }
        long long max=0;
        for(auto x:v){
            if(x>max){
                max=x;
            }
        }
        return max;
    }
};
