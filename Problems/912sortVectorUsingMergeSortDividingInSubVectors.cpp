class Solution {
public:
    void merge(vector<int> &v1,vector<int> &v2,vector<int> &final){
        int i=0,j=0,k=0;
        // vector<int> final;
        while(1){
            if(i==v1.size()){
                for(;j<v2.size();j++){
                    final[k] = v2[j];
                    k++;
                }
                break;
            }
            if(j==v2.size()){
                for(;i<v1.size();i++){
                    final[k] = v1[i];
                    k++;
                }
                break;
            }
            if(v1[i]<=v2[j]){
                final[k] = v1[i];
                    k++;
                i++;
            }else{
                final[k] = v2[j];
                    k++;
                j++;
            }
        }
        /* below one is also good for merging */
        // while(i<v1.size() and j<v2.size()){
        //     if(v1[i]<v2[j]){
        //         final[k] = v1[i];
        //         k++;
        //         // final.push_back(v1[i]);
        //         i++;
        //     }else{
        //         final[k] = v2[j];
        //         k++;
        //         // final.push_back(v2[j]);
        //         j++;
        //     }
        // }
        // while(i<v1.size()){
        //     final[k] = v1[i];
        //         k++;
        //     // final.push_back(v1[i]);
        //     i++;
        // }
        // while(j<v2.size()){
        //     final[k] = v2[j];
        //         k++;
        //     // final.push_back(v2[j]);
        //     j++;
        // }
    }
    void mergeSort(vector<int>&v){
        if(v.size()<=1){
            return;
        }
        int mid = (v.size()-1)/2,i=0;
        vector<int>left;
        vector<int>right;
        for(i=0;i<=mid;i++){
            left.push_back(v[i]);
        }
        for(i=mid+1;i<v.size();i++){
            right.push_back(v[i]);
        }
        mergeSort(left);
        mergeSort(right);
        merge(left,right,v);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};