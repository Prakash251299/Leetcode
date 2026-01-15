Solution {
public:
    void display(vector<vector<int>>&v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    int maxRectArea(int i,int j,vector<vector<int>>&v){
        int maxV=v[i][j];
        int maxAr=v[i][j],minAr=v[i][j];
        for(int k=j-1;k>=0;k--){
            if(v[i][k]>=minAr){
                maxAr+=minAr;
                //cout<<minAr<<"+";
                if(maxV<maxAr){
                    maxV=maxAr;
                }
            }
            else{
                minAr=v[i][k];
                maxAr=v[i][k]*(j-k+1);
                if(maxV<maxAr){
                    maxV=maxAr;
                }
                //cout<<"\n"<<maxAr<<"\n";
            }
        }
        return maxV;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>v(m+1,vector<int>(n,0));
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                grid[i][j]=int(matrix[i][j]-'0');
            }
        }
        //display(grid);
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                v[i][j]=grid[i][j]+grid[i][j]*v[i+1][j];
            }
        }
        //display(v);




        //int c=maxRectArea(2,3,v);
        //cout<<"cVal: "<<c;
        //return 0;
        int maxV=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int rectAr=maxRectArea(i,j,v);
                if(maxV<rectAr){
                    maxV=rectAr;
                }
            }
        }
        return maxV;
    }
};
