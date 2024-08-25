class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    int binarySearch(vector<int>v,int a,int i,int j){
        if(i>j){
            return i;
        }
        int m = (i+j)/2;
        if(v[m]==a){
            return m;
        }
        if(v[m]>a){
            i=binarySearch(v,a,i,m-1);
        }else{
            i=binarySearch(v,a,m+1,j);
        }
        return i;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        if(nums.size()==1){
            return v.size();
        }
        for(int i=1;i<nums.size();i++){
            int t = binarySearch(v,nums[i],0,v.size()-1);
            if(t>=v.size()){
                v.push_back(nums[i]);
            }
            else{
                v[t] = nums[i];
            }
        }
        return v.size();
    }
};
