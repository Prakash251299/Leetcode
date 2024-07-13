class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        int count=n,i=0;
        while(v.size()>1){
            i = (i-1+k)%v.size();
            // cout<<i<<" "<<v[i]<<"\n";
            v.erase(v.begin()+i);
        }
        return v[0];
    }
};
