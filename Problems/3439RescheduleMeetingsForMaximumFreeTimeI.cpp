class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap;
        gap.push_back(startTime[0]);
        for(int i=0;i<endTime.size()-1;i++){
            gap.push_back(startTime[i+1]-endTime[i]);
        }
        gap.push_back(eventTime-endTime[endTime.size()-1]);
        int sum=0;
        k++;
        for(int i=0;i<k;i++){
            sum+=gap[i];
        }
        int max =sum;
        for(int i=0;i<gap.size()-k;i++){
            sum-=gap[i];
            sum+=gap[i+k];
            if(sum>max){max=sum;}
        }
        return max;

    }
};
