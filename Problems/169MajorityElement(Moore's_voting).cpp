class Solution {
public:
    int findMajorityHalf(vector<int>&v){
        int t=-1,c=0,n=v.size();
        // int t=-1,c=0,n=v.size();
        for(int i=0;i<v.size();i++){
            if(v[i]==t){
                c++;
            }else{
                if(c!=0) c--;
                if(c==0){
                    t = v[i];
                    c++;
                }
            }
        }
        c=0;
        for(auto x:v){
            if(x==t)
            c++;
        }
        //cout<<c<<"\n";
        if(c>n/2){
            // cout<<t<<" is majority element";
            return t;
        }
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        return findMajorityHalf(nums);
    }
};
