class Solution {
public:
    void countSort(vector<int> &v){
        unordered_map<int,int> m;
        int max = *max_element(v.begin(),v.end());
        int min = *min_element(v.begin(),v.end());
        for(auto x:v){
        
            if(m.find(x)!=m.end()){
                m[x] = m[x]+1;
            }
            else
                m[x] = 1;
        }
        int j=0;
        v.clear();
        for(int i=min;i<=max;i++){
            if(m.find(i)!=m.end()){
                for(int k = 0;k<m[i];k++){
                    v.push_back(i);
                }
            }
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        countSort(nums);
        // MergeSort(nums,0,nums.size()-1);
        return nums;
    }
};