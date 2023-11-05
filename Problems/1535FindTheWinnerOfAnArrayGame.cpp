class Solution {
public:
    int max(vector<int>& arr){
        int max=arr[0];
        for(auto x:arr){
            if(x>max){
                max = x;
            }
        }
        return max;
    }
    vector<int> compare(vector<int>& arr, int k){
        int a=0,b=0;
        int ci=0,cj=0;
        vector<int>v;
        int i=0,j=1;
        for(;i<arr.size() && j<arr.size();){
            if(arr[i]>arr[j]){
                ci++;
                if(i>j){
                    j=i+1;
                }else{
                    j=j+1;
                }
                cj=0;
            }else{
                cj++;
                if(j>i){
                    i=j+1;
                }else{
                    i=i+1;
                }
                ci=0;
            }
            if(ci>=k){
                v.push_back(i);
                return v;
            }
            if(cj>=k){
                v.push_back(j);
                return v;
            }
        }
        v.push_back(ci);
        v.push_back(cj);
        return v;
    }
    int getWinner(vector<int>& arr, int k) {
        /* If k>arr.size() then max element is the only which on any time repeatition will be the winner */
        if(k>=arr.size()){
            return max(arr);
        }
        /* Sliding window for two elements for comparision */
        vector<int>v=compare(arr,k);
        if(v.size()==1){
            return arr[v[0]];
        }else{
            /* If after any repeatition no elements found to be the winner then max of array will be the winner */
            return max(arr);
        }
    }
};
