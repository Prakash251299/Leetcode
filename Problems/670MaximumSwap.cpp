class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    int vecToInt(vector<int>v){
        int m = 1;
        int res = 0;
        for(int i=v.size()-1;i>=0;i--){
            res = res+v[i]*m;
            m*=10;
        }
        return res;
    }

    int maximumSwap(int num) {
        int n=num;
        vector<int>u;
        vector<int>v;
        while(n!=0){
            v.push_back(n%10);
            n/=10;
        }
        u = v;
        reverse(u.begin(),u.end());
        sort(v.begin(),v.end(),greater<int>());
        int k=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=u[i]){
                for(int j=i+1;j<v.size();j++){
                    if(u[j]==v[i]){
                        k = j;
                    }
                }
                int t = u[i];
                u[i] = u[k];
                u[k] = t;
                break;

            }
        }
        int res = vecToInt(u);
        return res;
    }
};
