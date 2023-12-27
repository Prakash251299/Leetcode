class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0, max=neededTime[0], sum=neededTime[0];
        for(int i=1;i<neededTime.size();i++){
            if(colors[i]!=colors[i-1]){
                sum = sum-max;
                cost += sum;
                sum = neededTime[i];
                max = neededTime[i];
            }else{
                if(neededTime[i]>max){
                    max = neededTime[i];
                }
                sum += neededTime[i];
            }
        }
        /* At the end when the last two colors are same again the cost should be updated */
        if(colors[neededTime.size()-1]==colors[neededTime.size()-2]){
            sum = sum-max;
            cost += sum;
        }
        return cost;
    }
};
