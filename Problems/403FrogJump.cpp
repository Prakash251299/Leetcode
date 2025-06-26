class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,set<int>> m;
        set<int> s;
        int i = 0, j = 0;
        m[stones[0]].insert(1);
        for(i=0;i<stones.size();i++){
            for(auto x:m[stones[i]]){
                if(binary_search(stones.begin(),stones.end(),stones[i]+x)){
                    if(x!=0){
                        if(x-1!=0)
                        m[stones[i]+x].insert(x-1);
                        m[stones[i]+x].insert(x);
                        m[stones[i]+x].insert(x+1);
                    }
                }
            }
        }
        
        for(i=0;i<stones.size();i++){
            cout<<stones[i]<<":";
            for(auto x:m[stones[i]]){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        if(m[stones[stones.size()-1]].size()!=0){
            return true;
        }else{
            return false;
        }
    }
};
