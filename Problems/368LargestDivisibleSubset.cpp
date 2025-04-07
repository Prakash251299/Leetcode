class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = 0;
        vector<int>sz(nums.size(),1);
        vector<int>ind(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            ind[i] = i;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(sz[i]<sz[j]+1){
                        sz[i] = sz[j]+1;
                        ind[i] = j;
                        if(sz[i]>=sz[m]){
                            m = i;
                        }
                    }
                }
            }
        }
        // cout<<"\nsz\n";
        // display(sz);
        // cout<<"ind\n";
        // display(ind);
        // cout<<"m:"<<m;
        int prev = m+1;
        vector<int>v;
        while(m!=prev){
            prev = m;
            v.push_back(nums[m]);
            m = ind[m];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
