class Solution {
public:
    void displayMap(map<int,int>m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        cout<<"\n";
    }
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        map<int,int>m;
        map<int,int>m1;
        for(auto x:nums){
            ++m[x];
        }
        int count=0,prev=-1;

        while(m.size()!=0){
            prev=-1;
            count=0;
            m1 = m;
            displayMap(m1);
            for(auto x:m1){
                if(count==k){
                    count=0;
                    break;
                }
                if(x.first==prev){
                    continue;
                }
                if(prev>=0 && x.first-prev>1){
                    return false;
                }
                prev = x.first;
                --m[x.first];
                if(m[x.first]<=0){
                    m.erase(x.first);
                }
                count++;
            }
        }
        if(count==k){
            return true;
        }
        return false;
    }
};
