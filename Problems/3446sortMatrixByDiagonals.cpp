class Solution {
public:
    void display(vector<vector<int>>&arr){
    for(auto x:arr){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void sortDiagIncr(vector<vector<int>>&arr,int i, int j, int n){
    int i1=i,j1=j;
    vector<int>v;
    for(;j<n;i++,j++){
        v.push_back(arr[i][j]);
    }
    sort(v.begin(),v.end());
    i=i1;j=j1;
    int k=0;
    for(;j<n;i++,j++){
        arr[i][j] = v[k];
        k++;
    }
}

void sortDiagDecr(vector<vector<int>>&arr,int i, int j, int n){
    int i1=i,j1=j;
    vector<int>v;
    for(;i<n;i++,j++){
        v.push_back(arr[i][j]);
    }
    sort(v.begin(),v.end(),greater<int>());
    i=i1;j=j1;
    int k=0;
    for(;i<n;i++,j++){
        arr[i][j] = v[k];
        k++;
    }
}

vector<vector<int>> caller(vector<vector<int>>&arr){
    int i=0,j=1,n=arr.size();
    for(;j<n;j++){
        sortDiagIncr(arr,i,j,n);
    }
    i=0;j=0;
    for(;i<n;i++){
        sortDiagDecr(arr,i,j,n);
    }
    return arr;
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]+=100000;
            }
        }
        caller(grid);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]-=100000;
            }
        }
        return grid;
    }
};
