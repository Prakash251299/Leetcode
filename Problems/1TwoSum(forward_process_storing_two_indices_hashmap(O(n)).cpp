class Solution {
public:
    void display(unordered_map<int,vector<int>>&m){
        for(auto x:m){
            cout<<x.first<<": ";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        //display(m);
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(m[target-x].size()!=0){
                if(target-x!=x){
                    return {i,m[target-x][0]};
                }else{
                    if(m[target-x].size()==2){
                        return {i,m[target-x][1]};
                    }
                }
            }
        }
        return {};
    }
};
