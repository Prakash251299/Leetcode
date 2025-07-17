class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        unordered_map<int,int>m;
        // priority_queue<int,vector<int>,greater<int>()>pq;
        priority_queue<int> pq;
        int max=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
            ++m[nums[i]];
        }
        v.push_back(pq.top());
        for(int i=1;i<=nums.size()-k;i++){
            --m[nums[i-1]];
            if(pq.top()==nums[i-1]){
                pq.pop();
            }
            while(!pq.empty() && m[pq.top()]<=0){
                pq.pop();
            }
            pq.push(nums[i+k-1]);
            ++m[nums[i+k-1]];
            if(pq.empty()){break;}
            v.push_back(pq.top());
        }
        return v;
    }
};
