class Solution {
public:
    void display(vector<vector<int>>& v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int maxi(int a, int b){
        if(a>b){
            return a;
        }
        return b;
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(mines.size()==n*n){
            return 0;
        }
        vector<vector<int>>m(n,vector<int>(n,1));
        for(auto x:mines){
            m[x[0]][x[1]] = 0;
        }
        // cout<<"original:\n";
        // display(m);
        vector<vector<int>>left(n,vector<int>(n,0));
        for(int i=0;i<m.size();i++){
            for(int j=1;j<m[0].size();j++){
                left[i][j] = m[i][j-1]*left[i][j-1]+m[i][j-1];
            }
        }
        // cout<<"Left:\n";
        // display(left);
        vector<vector<int>>right(n,vector<int>(n,0));
        for(int i=0;i<m.size();i++){
            for(int j=m[0].size()-2;j>=0;j--){
                right[i][j] = m[i][j+1]*right[i][j+1]+m[i][j+1];
            }
        }
        // cout<<"right\n";
        // display(right);
        vector<vector<int>>up(n,vector<int>(n,0));
        for(int i=0;i<m[0].size();i++){
            for(int j=1;j<m.size();j++){
                up[j][i] = m[j-1][i]*up[j-1][i]+m[j-1][i];
            }
        }
        // cout<<"up\n";
        // display(up);
        vector<vector<int>>down(n,vector<int>(n,0));
        for(int i=0;i<m[0].size();i++){
            for(int j=m.size()-2;j>=0;j--){
                down[j][i] = m[j+1][i]*down[j+1][i]+m[j+1][i];
            }
        }
        // cout<<"down\n";
        // display(down);
        int max=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==0){
                    continue;
                }
                int a = min(left[i][j],right[i][j]);
                int b = min(a,min(up[i][j],down[i][j]));
                int c = min(a,b);
                c+=1;
                if(c>max){
                    max = c;
                }
            }
        }
        return max;
    }
};
