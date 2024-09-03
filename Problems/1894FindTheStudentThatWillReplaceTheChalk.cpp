class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long t=0,sum=0;
        for(auto x:chalk){
            sum+=x;
        }
        t = k%sum;
        sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
            if(sum>t){
                return i;
            }
        }
        return 0;
    }
};
