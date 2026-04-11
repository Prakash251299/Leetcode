class Solution {
public:
    void display(vector<int>&v){
            for(auto x:v){
                cout<<x<<" ";
            }
            cout<<"\n";
    }
    void calculate(int i,int j,int l,int r,int &nSub){
        nSub+=(i-l+1)*(r-j+1);
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        int ind=0,nSub=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                if(dq.size()==k){
                    ind=dq.front()+1;
                    dq.pop_front();
                    left[i]=ind;
                }else{
                    left[i]=ind;
                }
                dq.push_back(i);
            }else{
                left[i]=ind;
            }
        }
        ind = nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2!=0){
                right[i]=ind-1;
                ind=i;
            }
        }

        // cout<<"left: ";
        // display(left);
        // cout<<"right: ";
        // display(right);
        dq.clear();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                dq.push_back(i);
                if(dq.size()==k||i==nums.size()-1){
                    calculate(dq.front(),dq.back(),left[i],right[i],nSub);
                    dq.pop_front();
                }
            }
        }
        return nSub;
    }
};
