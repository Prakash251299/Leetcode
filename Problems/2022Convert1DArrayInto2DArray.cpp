class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>v;
        int k=0;
        if(m*n!=original.size()){
            return v;
        }
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(original[k]);
                k++;
            }
            v.push_back(temp);
        }
        return v;
    }
};
