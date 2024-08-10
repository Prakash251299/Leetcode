class Solution {
public:
    int duplicateCheckWithRange(vector<vector<int>>v,int a,int b){
        unordered_map<int,int>m;
        for(int i=a;i<a+3;i++){
            for(int j=b;j<b+3;j++){
                if(v[i][j]<10 && v[i][j]>0){
                    if(m[v[i][j]]<=0){
                        m[v[i][j]]++;
                    }else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
        }        
        return 1;
    }
    int colSum(vector<vector<int>>v,int a,int b,int sum){
        int s1=0;
        for(int i=a;i<a+3;i++){
            s1=0;
            for(int j=b;j<b+3;j++){
                s1+=v[j][i];
            }
            if(s1!=sum){
                return 0;
            }
        }        
        return 1;
    }

    int rowSum(vector<vector<int>>v,int a,int b,int sum){
        int s1=0;
        for(int i=b;i<b+3;i++){
            s1=0;
            for(int j=a;j<a+3;j++){
                s1+=v[i][j];
            }
            if(s1!=sum){
                return 0;
            }
        }        
        return 1;
    }

    int diagSum(vector<vector<int>>v,int a,int b,int sum){
        int s1=0,s2=0;
        s1=v[b][a]+v[b+1][a+1]+v[b+2][a+2];      
        s2=v[b][a+2]+v[b+1][a+1]+v[b+2][a];
        if(s1!=s2){
            return 0;
        }      
        return 1;
    }

    int traverse(vector<vector<int>>v,int a,int b){
        cout<<a<<","<<b<<" ";
        if(duplicateCheckWithRange(v,a,b)==0){ // it contains duplicate
            cout<<"yes"<<"\n";
            return 0;
        }
        cout<<"no"<<"\n";
        int sum = v[a][b]+v[a+1][b]+v[a+2][b];
        int r = colSum(v,b,a,sum);
        
        if(r!=1){
            return 0;
        }
        r = rowSum(v,b,a,sum);
        
        if(r!=1){
            return 0;
        }
        r = diagSum(v,b,a,sum);
        
        if(r!=1){
            return 0;
        }

        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int a=0,b=0,count=0;
        if(a+3>grid.size() || b+3>grid[0].size()){
            return 0;
        }
        while(1){
            if(a+3<=grid.size() && b+3<=grid[0].size()){
                count+=traverse(grid,a,b);
                b++;
                if(b+3>grid[0].size()){ // make >= to ==
                    b=0;
                    a++;
                    if(a+3>grid.size()){
                        return count;
                    }
                }
            }else{
                break;
            }
            // cout<<"hi";
        }





        // if(a+3>grid[0].size() || b+3>grid.size()){
        //     return 0;
        // }
        // while(1){
        //     if(a+3<=grid[0].size() && b+3<=grid.size()){
        //         count+=traverse(grid,a,b);
        //         a++;
        //         if(a+3>=grid[0].size()){ // make >= to ==
        //             b++;
        //             a=0;
        //             if(b+3>=grid.size()){
        //                 return count;
        //             }
        //         }
        //     }
        //     // cout<<"hi";
        // }
        return 0;
    }
};
