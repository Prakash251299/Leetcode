class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(unordered_map<int,vector<int>>&m){
        for(auto x:m){
            cout<<x.first<<":";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>v(nums.size()+1);
        for(auto x:nums){
            ++m[x];
        }
        unordered_map<int,vector<int>>count;
        for(auto x:m){
            count[x.second].push_back(x.first);
            v[x.second]=1;
        }
        //display(count);
        //display(v);
        int c=0;
        vector<int>res;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0)continue;
            for(auto x:count[i]){
                if(c>=k){return res;}
                c++;
                res.push_back(x);
            }
        }
        
        return res;
    }
};
