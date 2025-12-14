class Solution {
public:
    void display(vector<long long>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void binarySearch(vector<long long>&prefSum,int i, int j, long long remHp, int lastInd, long long &ans){
        while(i<=j){
            int mid=(i+j)/2;
            if(prefSum[lastInd]-prefSum[mid]<=remHp){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
    }
    long long totalScore(int hp, vector<int>& damage, vector<int>& req) {
        vector<long long>prefSum;
        long long sum=0;
        long long remHp=0;
        int lastInd=0;
        long long res=0,ans=0;
        
        for(auto x:damage){
            sum+=x;
            prefSum.push_back(sum);
        }
        
        for(int i=0;i<damage.size();i++){
            ans=0;
            remHp=hp-req[i];
            if(remHp>=prefSum[i]){
                res+=i+1;continue;
            }
            if(remHp<0){
                continue;
            }
            lastInd=i;
            binarySearch(prefSum,0,i,remHp,lastInd,ans);
            res+=lastInd-ans;
        }
        return res;
    }
};
