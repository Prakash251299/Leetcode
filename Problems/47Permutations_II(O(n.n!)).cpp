class Solution {
public:
    void fun(vector<int>& nums, set<vector<int>>&res,map<int,int>m,vector<int>v,int c){
        if(c==nums.size()){
            //cout<<v.size();
            res.insert(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(m[i]==1){continue;}
            else{m[i]=1;}
            c++;
            v.push_back(nums[i]);
            fun(nums,res,m,v,c);
            m[i]=0;
            c--;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>s;
        map<int,int>m;
        vector<int>v;
        fun(nums,s,m,v,0);
        for(auto x:s){
            res.push_back(x);
        }
        return res;
    }
};
