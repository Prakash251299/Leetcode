class Solution {
public:
    int min(int a, int b, int c){
        if(a<=b and a<=c){
            return a;
        }
        if(b<=a and b<=c){
            return b;
        }
        if(c<=a and c<=b){
            return c;
        }
        return 0;
    }
    int min(int a, int b){
        if(a<b){
            return a;
        }
        return b;
    }
    void check(vector<vector<int>>&v,int i, int j, vector<vector<int>>arr){
        if(j-1<0){
            v[i][j] = arr[i][j] + min(v[i+1][j],v[i+1][j+1]);
        }else{
            if(j+1>=v.size()){
                v[i][j] = arr[i][j] + min(v[i+1][j-1],v[i+1][j]);
            }else{
                v[i][j] = arr[i][j] + min(v[i+1][j-1],v[i+1][j],v[i+1][j+1]);
            }
        }
        return;
    }

    void display(vector<vector<int>>v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        return;        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // vector<vector<int>>v;
        // vector<int>v1;
        vector<vector<int>>arr = matrix;

        int n = arr.size();
        vector<vector<int>> v(n,vector<int>(n, 0));
        // for(auto x:arr){
        //     for(auto y:x){
        //         v1.push_back(0);
        //     }
        //     v.push_back(v1);
        //     v1.clear();
        // }
        for(int i=0;i<n;i++){
            v[n-1][i] = arr[n-1][i];
        }
        // display(v);
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                check(v,i,j,arr);
            }
        }
        // display(v);
        int min=v[0][0];
        for(int i=0;i<n;i++){
            if(v[0][i]<min){
                min = v[0][i];
            }
        }
        return min;
    }
};
