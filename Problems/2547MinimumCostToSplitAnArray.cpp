class Solution {
public:
    void display(map<int,map<int,int>>&m){
        for(auto x:m){
            cout<<x.first<<"\n";
            for(auto y:x.second){
                cout<<y.first<<": "<<y.second<<"\n";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    void display(map<int,int>m){
        for(auto x:m){
            cout<<x.first<<": "<<x.second<<"\n";
        }
        cout<<"\n";
    }

    int minCost(vector<int>& nums, int k) {
        map<int,int>cost;
        cost[-1] = 0;
        cost[0] = k;
        for(int i=1;i<nums.size();i++){
            cost[i] = cost[i-1]+k;
            int c=0;
            map<int,int>m;
            for(int j=i;j>=0;j--){
                ++m[nums[j]];
                if(m[nums[j]]==2){
                    c+=2;
                }else{
                    if(m[nums[j]]>2){
                        c+=1;
                    }
                }
                if(c+cost[j-1]+k<cost[i]){
                    cost[i] = c+cost[j-1]+k;
                }
            }
        }
        // display(cost);
        return cost[nums.size()-1];
    }
};
