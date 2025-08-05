class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    vector<int> countSmaller(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]+=10001;
        }
        int maxv=*max_element(nums.begin(),nums.end());
        //maxv++;
        vector<int>arr(maxv+1,0);
        vector<int>res(nums.size(),0);
        unordered_map<int,int>m;
        
        for(int i=nums.size()-1;i>=0;i--){
            int t=nums[i]&-nums[i];
            int p=nums[i]-t;
            int s=0;
            while(p>0){
                s+=arr[p];
                p-=p&-p;
            }
            //res[i]=max({s,arr[nums[i]]});
            res[i]=s+arr[nums[i]]-m[nums[i]];
            
            arr[nums[i]]=1+arr[nums[i]];
            //display(arr);
            //res[i]=s;
            int j=nums[i];
            j+=j&-j;
            while(j<=maxv){
                arr[j]=arr[j]+1;
                j+=j&-j;
            }
            ++m[nums[i]];
            //display(arr);
        }
        return res;
    }
};
