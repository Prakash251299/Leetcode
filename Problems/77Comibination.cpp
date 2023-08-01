class Solution {
public:
    vector<vector<int>>x;
    void fun(vector<int>v,int i,int k,int size){
        if(i>k){
            return;
        }
        v.push_back(i);
        if(v.size()==size){
            x.push_back(v);
        }
        for(int j=i;j<=k;j++){
            i++;
            fun(v,i,k,size);
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        int i=1;
        vector<int>v;
        for(;i<=n;i++){
            fun(v,i,n,k);
        }
        return x;
    }
};