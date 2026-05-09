class Solution {
public:
    void traverseSpiral(vector<vector<int>>& m, int &dir, vector<int>&res,int i,int j){
        if(res.size()==m.size()*m[0].size())return;
        if(dir==0){
            while(j<m[0].size() and m[i][j]!=1000){
                res.push_back(m[i][j]);
                m[i][j]=1000;
                j++;
            }
            j--;i++;
            dir=1;
            traverseSpiral(m,dir,res,i,j);
            return;
        }
        if(dir==1){
            while(i<m.size() and m[i][j]!=1000){
                res.push_back(m[i][j]);
                m[i][j]=1000;
                i++;
            }
            j--;i--;
            dir=2;
            traverseSpiral(m,dir,res,i,j);
            return;
        }
        if(dir==2){
            while(j>=0 and m[i][j]!=1000){
                res.push_back(m[i][j]);
                m[i][j]=1000;
                j--;
            }
            j++;i--;
            dir=3;
            traverseSpiral(m,dir,res,i,j);
            return;
        }
        if(dir==3){
            while(i>=0 and m[i][j]!=1000){
                res.push_back(m[i][j]);
                m[i][j]=1000;
                i--;
            }
            j++;i++;
            dir=0;
            traverseSpiral(m,dir,res,i,j);
            return;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int dir=0;
        int i=0,j=0;
        traverseSpiral(matrix,dir,res,i,j);
        return res;
    }
};
