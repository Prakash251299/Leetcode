class Solution {
public:
    long long placeLadder(vector<int>&v){
        long long max=0;
        int ind=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>max){
                max = v[i];
                ind = i;
            }
        }
        v.erase(v.begin()+ind);
        return max;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int>v = heights;
        vector<int>a;
        int i=0,diff=0;
        for(i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]){

            }else{
                diff = v[i+1]-v[i];
                a.push_back(diff);
                if(bricks>=diff){
                    bricks-=diff;
                }else{
                    if(ladders<=0){
                        return i;
                    }else{
                        int b = placeLadder(a);
                        if(diff!=b){
                            bricks+=b;
                            bricks-=diff;
                        }
                        ladders--;
                    }
                }
            }
        }
        return i;
    }
};
