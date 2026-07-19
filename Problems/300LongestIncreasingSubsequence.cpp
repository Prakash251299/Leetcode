class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int binarySearch(vector<int>&v,int a,int i,int j){
        if(i>j){
            return i;
        }
        int mid=(i+j)/2;
        if(v[mid]==a)return mid;
        if(a<v[mid]){
            return binarySearch(v,a,i,mid-1);
        }
        return binarySearch(v,a,mid+1,j);
    }
    int search(int a,vector<int>&v){
        return binarySearch(v,a,0,v.size()-1);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int ind = search(nums[i],v);
            if(ind>=v.size()){
                v.push_back(nums[i]);
            }else{
                v[ind]=nums[i];
            }
        }
        return v.size();
    }
};
