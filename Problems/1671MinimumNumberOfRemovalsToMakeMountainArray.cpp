class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int insert(int a, vector<int>v){
        if(v.size()==0){
            return 0;
        }
        int i=0,j=v.size()-1;
        int mid = 0;
        while(i<j){
            mid = (i+j)/2;
            if(v[mid]==a){
                return mid;
            }else{
                if(v[mid]>a){
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }
        }
        // Below case happens when the number to search is the smallest of all current numbers
        if(j<0){ 
            return 0;
        }

        if(v[j]<a){
            j++;
        }
        // cout<<i<<" "<<mid<<" "<<j<<"\n";
        return j;
    }
    void lss(vector<int>nums,vector<int>&v1){
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int j = insert(nums[i],v);
            if(j<v.size()){
                v[j] = nums[i];
            }else{
                v.push_back(nums[i]);
            }
            v1[i] = v.size();
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1(n,0);
        vector<int>v2(n,0);


        // v1.push_back(2);
        // v1.push_back(7);
        // v1.push_back(8);
        // v1.push_back(12);
        // // v1.push_back(2);
        // int a = insert(0,v1);
        // cout<<a;
        // return 0;
        

        vector<int>t = nums;
        lss(nums,v1);
        // display(v1);
        reverse(nums.begin(),nums.end());
        lss(nums,v2);
        reverse(v2.begin(),v2.end());
        // display(v2);
        
        ///////////////////////////////////////////////
        //checking whether it is possible to build mountain at the index or not
        unordered_map<int,int>m;
        int min=t[0];
        for(int i=0;i<t.size();i++){
            if(t[i]>min){
                m[i] = 1;
            }else{
                min = t[i];
            }
        }
        min = t[t.size()-1];
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]>min){
                ++m[i];
            }else{
                min = t[i];
            }
        }
        //////////////////////////////////////////////

        int max=0;
        for(int i=1;i<v1.size()-1;i++){
            if(v1[i]+v2[i]>max && m[i]==2){
                max = v1[i]+v2[i];
            }
        }
        // cout<<l<<"\n";
        return nums.size()-max+1;
    }
};
