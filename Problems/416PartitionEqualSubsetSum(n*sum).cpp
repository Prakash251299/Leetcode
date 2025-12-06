class Solution {
public:
    void display(set<int>&subset){
        for(auto x:subset){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(auto x:nums){
            sum+=x;
        }
        set<int>subset;
        subset.insert(0);
        for(auto x:nums){
            set<int> temp=subset;
            for(auto y:temp){
                subset.insert(x+y);
                if(sum-(x+y)==x+y){
                    return true;
                }
            }
        }
        //display(subset);
        return false;
    }
};
