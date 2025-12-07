class Solution {
public:
    void display(unordered_map<int, unordered_set<int>>&m){
        for(auto x:m){
            cout<<x.first<<" ";
            for(auto y:x.second){
                cout<<y<<",";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    int sumOfArrayElements(vector<int>&nums){
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        return sum;
    }
    
    void getAllSums(vector<int>&nums, unordered_map<int, unordered_set<int>>&leftMap, int i, int j){
        unordered_map<int, unordered_set<int>>temp;
        leftMap[0].insert(0);
        //cout<<leftMap[0].count(7);
        for(;i<j;i++){
            for(auto x:leftMap){
                for(auto y:x.second){
                    temp[x.first+1].insert(y+nums[i]);
                }
            }
            for(auto x:temp){
                for(auto y:x.second){
                    leftMap[x.first].insert(y);
                }
            }
        }
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        unordered_map<int, unordered_set<int>>leftMap;
        unordered_map<int, unordered_set<int>>rightMap;
        
        getAllSums(nums,leftMap,0,nums.size()/2);
        //display(leftMap);
        
        getAllSums(nums,rightMap,nums.size()/2,nums.size());
        //display(rightMap);
        int n=nums.size();
        int totalSum=sumOfArrayElements(nums);
        //cout<<leftMap[2].count(8);
        for(int r=0;r<=n/2;r++){
            for(auto x:rightMap[r]){
                for(int i=max(1,r);i<=n/2;i++){
                    if((totalSum*i)%n!=0)
                        continue;
                    int tempSum=(totalSum*i)/n-x;
                    if(tempSum<0){
                        continue;
                    }
                    if(leftMap[i-r].count(tempSum))
                        return true;
                }
            }
        }
        return 0;
    }
};
