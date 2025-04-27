class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>rem(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem[i] = sum%k;
        }
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(rem[i]==0){
                if(i>0){
                    // cout<<"1";
                    return true;
                }
            }
            if(m[rem[i]]!=0 && m[rem[i]]+1<i+1){
                // cout<<"2";
                return true;
            }
            if(m[rem[i]]==0){
                m[rem[i]] = i+1;
            }
        }
        return false;
    }
};
