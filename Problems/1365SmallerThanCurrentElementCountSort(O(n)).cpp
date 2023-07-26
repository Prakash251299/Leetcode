/* Time complexity: O(n log n) */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        vector<int> s;
        int i=0,j=0;
        for(i=0;i<=100;i++){
            v.push_back(0);
        }
        for(i=0;i<nums.size();i++){
            v[nums[i]] = v[nums[i]]+1;
        }
        for(i=0;i<=100;i++){
            if(v[i]!=0){
                for(j=0;j<v[i];j++){
                    s.push_back(i);
                }
            }
        }
        int b=0;
        unordered_map<int,int> m;
        m[s[0]] = 0;
        for(i=s.size()-1;i>=0;i--){
            b=0;
            for(j=1;j<i+1;j++){
                if(s[i]==s[i-j]){
                    b++;
                }else{
                    m[s[i]] = i-b;break;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = m[nums[i]];
        }
        return nums;
    }
};