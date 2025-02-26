class Solution {
public:
    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int numOfSubarrays(vector<int>& arr) {
        vector<int>odd(arr.size(),0);
        int sum = 0;
        int mod = 1000000007;
        vector<int>even(arr.size(),0);
        if(arr[0]%2==0){
            even[0] = 1;
        }else{
            odd[0] = 1;
            sum+=1;
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]%2!=0){
                odd[i] = 1+even[i-1];
                sum+=odd[i];
                sum = sum%mod;
                even[i] = odd[i-1];
            }else{
                odd[i] = odd[i-1];
                sum+=odd[i];
                sum = sum%mod;
                even[i] = even[i-1]+1;
            }
        }
        return sum;
    }
};
