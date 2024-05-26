class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int max1=0,sum=0,m=0;
        vector<int>v(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            max1=0;
            m=0;
            for(int j=1;j<=k;j++){
                sum = 0;
                if(i-j+1<0){
                    break;
                }
                m = max(m,arr[i-j+1]);
                sum += m*j;
                if(i-j>=0){
                    sum+=v[i-j];
                }
                if(max1<sum){
                    max1 = sum;
                }
            }
            v[i] = max1;
        }
        return v[v.size()-1];
    }
};
