class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void intToBinaryCounts(vector<int>&v,int n){
        int i=0;
        while(n!=0){
            if(n%2!=0){
                v[29-i]++;
            }
            n/=2;
            i++;
        }
    }

    void intToBinaryCountsDeduct(vector<int>&v,int n){
        int i=0;
        while(n!=0){
            if(n%2!=0){
                v[29-i]--;
            }
            n/=2;
            i++;
        }
    }

    int binaryToInteger(vector<int>v){
        int a = 0;
        for(int i=v.size()-1;i>=0;i--){ // 
            if(v[i]>0){
                a = a + pow(2,v.size()-1-i);
            }
        }
        return a;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res=pow(10,9),i=0,j=0,c=0,end=0;
        vector<int>v(30,0);
        // intToBinaryCounts(v,6);
        // intToBinaryCounts(v,6);
        // display(v);
        // cout<<binaryToInteger(v);


        
        for(;i<nums.size() && j<nums.size();){
            if(binaryToInteger(v)>=k){
                // write code for i and j increment
                if(j-i<=0){
                    return 1;
                }
                if(c<res){
                    res=c;
                }
                intToBinaryCountsDeduct(v,nums[i]);
                i++;
                c--;
            }else{
                if(end==1){
                    break;
                }
                // write code for j increment
                intToBinaryCounts(v,nums[j]);
                c++;
                if(j+1>=nums.size()){
                    end=1;
                    if(binaryToInteger(v)>=k){
                        continue;
                    }
                }
                j++;
            }
        }
        display(v);



        // for(int i=0;i<nums.size();i++){
        //     res|=nums[i];
        // }
        if(res==pow(10,9)){
            return -1;
        }
        return res;
    }
};
