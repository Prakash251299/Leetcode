class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void maxAvailableGapForCurrentEvent(int &eventTime, vector<int>& startTime, vector<int>& endTime,vector<int>&leftGap){
        // vector<int>leftGap;
        leftGap.push_back(0);
        for(int i=1;i<startTime.size();i++){
            if(i==1){
                leftGap.push_back(startTime[i-1]);
                continue;
            }
            leftGap.push_back(max(leftGap[i-1],startTime[i-1]-endTime[i-2]));
            // if(leftGap[i-1]<startTime[i-1]-endTime[i-2]){
            //     leftGap.push_back(startTime[i-1]-endTime[i-2]);
            // }else{
            //     leftGap.push_back(leftGap[i-1]);
            // }
        }
        vector<int>rightGap(startTime.size(),0);
        rightGap[rightGap.size()-1] = 0;
        for(int i=rightGap.size()-2;i>=0;i--){
            if(i==rightGap.size()-2){
                rightGap[i] = eventTime-endTime[i+1];
                continue;
            }
            rightGap[i] = max(rightGap[i+1],startTime[i+2]-endTime[i+1]);
        }
        // display(leftGap);
        // display(rightGap);
        for(int i=0;i<leftGap.size();i++){
            leftGap[i] = max(leftGap[i],rightGap[i]);
        }
        // display(leftGap);
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gap;
        maxAvailableGapForCurrentEvent(eventTime,startTime,endTime,gap);
        int max = 0;
        for(int i=0;i<startTime.size();i++){
            int diff=0;
            if(i==0){
                diff = startTime[i]+(startTime[i+1]-endTime[i]);
            }else{
                if(i==startTime.size()-1){
                    diff = (startTime[i]-endTime[i-1])+eventTime-endTime[i];
                }else{
                    diff = (startTime[i]-endTime[i-1])+(startTime[i+1]-endTime[i]);
                }
            }
            if(gap[i]>=endTime[i]-startTime[i]){
                diff+=endTime[i]-startTime[i];
            }
            if(diff>max){
                max = diff;
            }
        }
        return max;
    }
};
