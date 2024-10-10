class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int maxWidthRamp(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        int s=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(s<nums[i]){
                v[i] = nums[i];
                s = nums[i];
            }else{
                v[i]=s;
            }
        }
        // display(v);
        int i=0;
        int m=0;
        for(int j=i+1;j<nums.size();){
            if(v[j]>=nums[i]){
                if(j-i>m){
                    m = j-i;
                }
                j++;
            }else{
                i++;
            }
        }
        return m;
    }
};
