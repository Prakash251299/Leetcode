class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long sum=0;
        for(int i=0;i<happiness.size();i++){
            if(k==0){
                break;
            }
            // if(happiness.size()-1-i<0){
            //     break;
            // }
            if(happiness[happiness.size()-1-i]-i<=0){
                break;
            }
            sum+=happiness[happiness.size()-1-i]-i;
            k--;
        }
        cout<<sum;
        return sum;
    }
};
