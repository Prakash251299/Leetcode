class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      //vector<int>v;
      vector<int>res;
      deque<int> v;
      //v.push_back(INT_MIN);
      for(int i=0;i<nums.size();i++){
        // v.push_back(i);
        while(v.size()!=0){
          if(nums[v[v.size()-1]]<nums[i]){
            v.pop_back();
          }else break;
        }
        // v.push_back(i);
        while(v.size()!=0){
          if(i-v[0]>=k){
            v.pop_front();
            // cout<<"popped";
          }else break;
        }
        v.push_back(i);
    
        if(i>=k-1){
          res.push_back(nums[v[0]]);
        }
      }
      return res;
    }
};
