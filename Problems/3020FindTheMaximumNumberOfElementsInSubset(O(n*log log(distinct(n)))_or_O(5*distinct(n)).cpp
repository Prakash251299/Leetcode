class Solution {
public:
    int check(long long a,unordered_map<int,int>&m){
        int c=0;
        if(a==1){
            if(m[a]%2==0){
                return m[a]-1;
            }else{
                return m[a];
            }
        }
        while(1){
            if(!m.contains(a)){
                break;
            }
            if(m[a]==1){
                c+=1;
                break;
            }
            if(m[a]>1){
                c+=2;
            }
            if(a>100000)break;
            a*=a;
        }
        if(c%2==0){
            return c-1;
        }
        return c;
    }
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        int res=0;
        for(auto x:m){
            res = max(res,check(x.first,m));
        }
        return res;
    }
};
