class Solution {
public:
    void display(map<int,int>&m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
    }
    int numTrees(int n) {
        map<int,int>m;
        // int res=0;
        m[0]=1;
        m[1]=1;
        if(n==1){
            return 1;
        }
        int sum=0;
        for(int i=2;i<=n;i++){
            sum=0;
            for(int j=0;j<i;j++){
                // cout<<"sum: "<<sum<<"mult: "<<m[j]*m[i-j-1]<<"\n";
                sum=sum+(m[j]*m[i-j-1]);
            }
            m[i]=sum;
        }
        // display(m);
        return m[n];
    }
};
