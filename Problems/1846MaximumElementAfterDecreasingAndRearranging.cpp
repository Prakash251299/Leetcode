class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>a){
                a++;
            }
        }
        return a;
    }
};
