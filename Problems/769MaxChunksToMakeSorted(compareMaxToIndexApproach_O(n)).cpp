class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxv=arr[0],c=0;
        for(int i=0;i<arr.size();i++){
            if(maxv<arr[i]){
                maxv=arr[i];
            }
            if(maxv==i){
                c++;
            }
        }
        return c;
    }
};
