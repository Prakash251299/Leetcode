class Solution {
public:
    void merge(vector<int> &v,int a1, int b1, int a2, int b2){
        int i=a1,j=a2,k=0;
        vector<int> final;
        while(1){
            if(i==b1+1){
                for(;j<=b2;j++){
                    final.push_back(v[j]);
                }
                break;
            }
            if(j==b2+1){
                for(;i<=b1;i++){
                    final.push_back(v[i]);
                }
                break;
            }
            if(v[i]<=v[j]){
                final.push_back(v[i]);
                i++;
            }else{
                final.push_back(v[j]);
                j++;
            }
        }
        for(i=a1;i<=b2;i++){
        	v[i] = final[i-a1];
		}
    }
    void mergeSort(vector<int>&v, int a, int b){
        if(a>=b){
            return;
        }
        int mid = (a+b)/2;
        mergeSort(v,a,mid);
        mergeSort(v,mid+1,b);
        merge(v,a,mid,mid+1,b);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};