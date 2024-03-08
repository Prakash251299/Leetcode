class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>v(102,0);
        for(auto x:nums){
            ++v[x];
        }
        int maxCount=0,sum=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==maxCount){
                sum+=v[i];
            }
            if(v[i]>maxCount){
                sum = v[i];
                maxCount = v[i];
            }
        }
        return sum;
    }
};
