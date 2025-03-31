class Solution {
public:
    int checkPossibilty(long long mid,vector<int>&v,int k){
        long long i=0,j=1;
        k--;
        for(;j<v.size();j++){
            long long diff = v[j]-v[i];
            if(diff>=mid){
                k--;i=j;
            }
            if(k<=0){
                return 1;
            }
        }
        return 0;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        long long best=0;
        long long i=1;
        // long long j=(position[position.size()-1]-1)*m;
        long long j = pow(10,9);
        while(i<=j){
            long long mid=(i+j)/2;
            if(checkPossibilty(mid,position,m)){
                i = mid+1;
                best = mid;
            }else{
                j=mid-1;
            }
        }
        return best;
    }
};
