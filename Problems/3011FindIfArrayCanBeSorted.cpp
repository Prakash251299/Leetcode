class Solution {
public:
    int onesInBinaryOfIntegers(int n){
        // string s = "";
        int c=0;
        while(n!=0){
            if(n%2!=0){
                c++;
                // s.push_back('1');
            }else{
                // s.push_back('0');
            }
            n/=2;
        }
        // reverse(s.begin(),s.end());
        // cout<<s<<"\n";
        return c;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    bool canSortArray(vector<int>& nums) {
        int c=0;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            c = onesInBinaryOfIntegers(nums[i]);
            v.push_back(c);
        }
        // display(v);
        // cout<<c;
        int flag=0,i=0,j=1;
        while(1){
            i=0;j=1;
            flag=0;
            while(1){
                if(j>=nums.size()){
                    break;
                }
                if(nums[i]>nums[j]){
                    if(v[i]==v[j]){
                        // swap(nums,i,j);
                        int t =nums[i];
                        nums[i] = nums[j];
                        nums[j] = t;
                        flag = 1;
                    }
                }
                i++;
                j++;
            }
            if(flag==0){
                break;
            }
        }
        bool res = true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                res = false;
                break;
            }
        }
        return res;
    }
};
