class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min = arrays[0][0];
        int max=arrays[0][arrays[0].size()-1];
        int diff=0;
        for(int i=1;i<arrays.size();i++){
            int t1 = arrays[i][0]-max;
            if(t1<0){
                t1*=-1;
            }
            int t2 = arrays[i][arrays[i].size()-1]-min;
            if(t2<0){
                t2*=-1;
            }
            if(t1>=t2){
                if(diff<t1){
                    diff=t1;
                }
            }else{
                if(diff<t2){
                    diff=t2;
                }
            }
            if(max<arrays[i][arrays[i].size()-1]){
                max = arrays[i][arrays[i].size()-1];
            }
            if(min>arrays[i][0]){
                min = arrays[i][0];
            }
        }
        return diff;
    }
};
