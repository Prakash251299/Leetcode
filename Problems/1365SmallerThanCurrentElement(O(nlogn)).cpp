/* Time complexity: O(n log n) */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        unordered_map<int,int> m;
        sort(nums.begin(),nums.end()); // Sort the vector
        m[nums[0]] = 0;
        int b=0;
        for(int i=nums.size()-1;i>=0;i--){
            b=0;
            /* Check for duplicates */
            for(int j=1;j<i+1;j++){
                if(nums[i]==nums[i-j]){
                    b++;
                }else{
                    m[nums[i]] = i-b;break; // Saves counts in map
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            v[i] = m[v[i]]; // Accessing data from map
        }
        return v;
    }
};
