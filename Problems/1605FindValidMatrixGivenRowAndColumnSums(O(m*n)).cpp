class Solution {
public:
    void display(vector<vector<int>>v){
        for(auto y:v){
            for(auto x:y)
            cout<<x<<" ";
            cout<<endl;
        }
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>v(rowSum.size(),vector<int>(colSum.size(),0));
        // cout<<v.size();
        // display(v);
        vector<vector<int>>res;
        for(int i=0;i<rowSum.size();i++){
            if(rowSum[i]==0){
                continue;
            }
            for(int j=0;j<colSum.size();j++){
                if(colSum[j]==0){
                    continue;
                }
                if(rowSum[i]<colSum[j]){
                    v[i][j] = rowSum[i];
                    colSum[j]-=rowSum[i];
                    rowSum[i]-=rowSum[i];
                }else{
                    v[i][j] = colSum[j];
                    rowSum[i]-=colSum[j];
                    colSum[j]-=colSum[j];
                }
                // dis(rowSum);
                // dis(colSum);
                // cout<<"\n";
            }
            // display(v);
            // cout<<"\n";
        }
        return v;
    }
    void dis(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
