class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size()==0){
            if(startFuel>=target){
                return 0;
            }
            return -1;
        }
        if(startFuel>=target){
            return 0;
        }
        int fuel=startFuel;
        int diff=0;
        priority_queue<int>pq;
        int c=0;
        for(int i=0;i<stations.size();i++){
            if(i>0){
                diff = stations[i][0]-stations[i-1][0];
            }else{
                diff = stations[i][0];
            }
            if(fuel>=diff){
                fuel-=diff;
                diff=0;
                pq.push(stations[i][1]);
                continue;
            }else{
                diff -= fuel;
                fuel = 0;
                while(!pq.empty()){
                    c++;
                    fuel = pq.top();
                    pq.pop();
                    if(fuel>=diff){
                        fuel-=diff;
                        diff = 0;
                        break;
                    }
                    diff -= fuel;
                    fuel = 0;
                }
                if(diff>0){
                    // cout<<"1st";
                    return -1;
                }
            }
            pq.push(stations[i][1]);
        }
        // cout<<"count: "<<c<<"\n";
        diff = target - stations[stations.size()-1][0];
        // cout<<"diff: "<<diff<<"\n";
        // cout<<"fuel: "<<fuel<<"\n";
        
        if(fuel>=diff){
            fuel-=diff;
            diff=0;
            return c;
        }
        else{
            diff-=fuel;
            fuel=0;
            while(!pq.empty()){
                c++;
                fuel=pq.top();
                pq.pop();
                if(fuel>=diff){
                    fuel-=diff;
                    diff=0;
                    break;
                }
                diff-=fuel;
                fuel=0;
            }
            if(diff>0){
                return -1;
            }
        }
        return c;
    }
};
