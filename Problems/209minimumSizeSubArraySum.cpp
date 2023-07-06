class Solution {
public:
    int minSubArrayLen(int target, vector<int>&v) {
        int currStart = 0, currEnd = 0, i = 0;
        long long sum = 0;
        vector<int> count;
        while(1){
            if(currEnd==v.size()){
                break;
            }
            sum = sum + v[currEnd];
            if(sum>=target){
                for(;sum>=target;){
                    count.push_back(currEnd-currStart+1);
                    // }
                    sum = sum - v[currStart];
                    currStart = currStart+1;
                }
            }
            currEnd++;
        }
        if(count.size()==0){
            return 0;
        }
        int minCount = *min_element(count.begin(),count.end());
        return minCount;
    }
};