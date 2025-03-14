class Solution {
public:
    int mod = 1000000007;
    int kInversePairs(int n, int k) {
        if(k==0){
            return 1;
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            if(k==1){
                return 1;
            }else{
                return 0;
            }
        }
        int i=2,j=0;
        long long sum=0;
        unordered_map<long long,long long>m1;
        unordered_map<long long,long long>m2;
        m2[1] = 1;
        for(int i=3;i<=n;i++){
            m1 = m2;
            m2.clear();
            sum=0;
            for(j=1;j<=k;j++){
                sum=sum+m1[j];
                sum%=mod;

                if(j<i){
                    long long t = sum+1;
                    t%=mod;
                    m2[j] = t;
                }
                else{
                    sum = sum - m1[j-i];
                    sum = (sum+mod)%mod;
                    m2[j] = sum;
                }
                if(m2[j]==0){
                    break;
                }
            }
        }
        return m2[k];
    }
};
