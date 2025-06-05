class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int>m;
        int max=0;
        for(auto x:nums){
            ++m[x];
        }
        int c = m[1];
        if(c%2==0){
            max = c-1;
        }else{
            max = c;
        }
        // int curr=0;
        for(auto x:nums){
            if(x==1){continue;}
            int curr=1;
            long long a = x;
            while(m[a]>0){
                long long b = (long long)a*(long long)a;
                if(m[a]>=2 && m[b]>0){
                    curr+=2;
                }
                a=b;
            }
            if(curr>max){
                max=curr;
            }
        }
        return max;
    }
};
