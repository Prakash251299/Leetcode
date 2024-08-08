class Solution {
public:
    void traverse(int r,int c,int i, int j,int add,int t,vector<vector<int>>&res,int count){
        // cout<<add;
        if(count>=t){
            return;
        }
        vector<int>v;
        int temp = j;
        if(count!=0){
            i++;
            j++;
        }
        // if(i>=0)
        for(;j<=temp+add;j++){
            if(j<=c && i>=0 && j>=0 && i<=r){
                v.push_back(i);
                v.push_back(j);
                res.push_back(v);
                count++;
            }
            v.clear();
        }
        // if(j<=c)
        temp = i;
        i++;
        j--;
        // if(j<=c)
        for(;i<=temp+add;i++){
            if(i<=r && j<=c & i>=0 && j>=0){
                v.push_back(i);
                v.push_back(j);
                res.push_back(v);
                count++;
            }
            v.clear();
        }
        add++;
        temp=j;
        j--;
        i--;
        // if(i<=r)
        for(;j>=temp-add;j--){
            if(j>=0 && i<=r && j<=c && i>=0){
                v.push_back(i);
                v.push_back(j);
                res.push_back(v);
                count++;
            }
            v.clear();
        }
        temp=i;
        i--;
        j++;
        // if(j>=0)
        for(;i>=temp-add;i--){
            if(i>=0 && j>=0 && i<=r && j<=c){
                v.push_back(i);
                v.push_back(j);
                res.push_back(v);
                count++;
            }
            v.clear();
        }
        add++;
        traverse(r,c,i,j,add,t,res,count);
        return;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int t=rows*cols,add=1,c=0;
        vector<vector<int>>res;
        vector<int>v;
        // v.push_back(rStart);
        // v.push_back(cStart);
        // res.push_back(v);
        traverse(rows-1,cols-1,rStart,cStart,add,t,res,c);
        return res;
    }
};
