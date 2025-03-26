class Solution {
public:
    int max(vector<int>v){
        int max = INT_MIN;
        for(auto x:v){
            if(max<x){
                max=x;
            }
        }
        return max;
    }

    int avg(vector<int>v,int h){
        long long sum=0;
        for(auto x:v){
            sum+=x;
            // int t = x/h;
            // if(t*h==x){
            //     sum+=t;
            // }else{
            //     sum+=t+1;
            // }
        }
        // sum/=h;
        // sum = (sum+h-1)/h;
        // return int(sum);
        return int(sum+h-1)/h;
    }

    int fun(int mid,vector<int>v,int h){
        for(int k=0;k<v.size();k++){
            if(h<=0){
                return 0;
            }
            if(mid==0){
                return 0;
            }
            long long sum = (v[k]+mid-1)/mid;
            if(h>=sum){
                h-=sum;
            }else{
                return 0;
            }
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int j = max(piles);
        if(piles.size()==h){
            return j;
        }
        int i=avg(piles,h);
        int min = INT_MAX;
        while(i<=j){
            int mid = (i+j)/2;
            if(fun(mid,piles,h)){
                if(mid<min){
                    min=mid;
                }
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return min;
    }
};
