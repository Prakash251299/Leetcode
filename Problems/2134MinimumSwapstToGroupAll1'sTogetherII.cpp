class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int minSwaps(vector<int>& nums) {
        vector<int>v;
        vector<int>prefix;
        int sum=0;
        for(auto x:nums){
            v.push_back(x);
            sum+=x;
            prefix.push_back(sum);
        }
        if(sum==0){
            return 0;
        }
        int s=sum;
        for(auto x:nums){
            v.push_back(x);
            s += x;
            prefix.push_back(s);
        }
        int min = sum-prefix[sum-1];
        for(int i=0;i<v.size()-sum;i++){
            int j=i+sum;
            int t = sum-(prefix[j]-prefix[i]);
            if(t<min){
                min=t;
            }
        }
        return min;
    }
};
