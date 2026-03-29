class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> tgas=gas;
        vector<int> tcost=cost;
        for(auto x:tgas){
            gas.push_back(x);
        }
        for(auto x:tcost){
            cost.push_back(x);
        }
        int si=0,tot=0;
        int ind=-1,flag=0;
        for(int i=0;i<gas.size();i++){
            if(i-si+1>tgas.size())return si;
            int t = 0;
            t = gas[i]-cost[i];
            if(tot+t<0){
                si = i+1;
                tot=0;
            }else{
                tot+=t;
            }
        }
        return -1;
    }
};
