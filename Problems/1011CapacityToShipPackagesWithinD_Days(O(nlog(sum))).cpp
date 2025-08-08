class Solution {
public:
    int check(vector<int>&v,int max){
        int sum=0,c=0;
        for(int i=0;i<v.size();i++){
            if(sum+v[i]<max){
                sum+=v[i];
            }else{
                if(sum+v[i]==max){
                    sum=0;c++;
                }
                else{
                    sum=v[i];c++;
                }
            }
        }
        if(sum>0){
            c++;
        }
        return c;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        //int i=*max_element(weights.begin(),weights.end());,
        int i=0;
        for(auto x:weights){
            i=max(i,x);
        }
        int j=sum;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(check(weights,mid)>days){
                i=mid+1;
                continue;
            }else{
            //if(check(weights,mid)<=days){
                j=mid-1;
                ans=mid;
                continue;
            }
        }
        return ans;
    }
};
