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

    void getEnd(vector<vector<int>>&land,vector<vector<int>>&v,int i, int &j,vector<int>&temp){
        int i1 = i, j1 = j, k = 0;
        temp.push_back(i);
        temp.push_back(j);
        for(k = j;k<land[0].size();k++){
            if(land[i][k]==1){
                // no need of this
            }else{
                break;
            }
        }
        j1 = k-1;

        for(k = i;k<land.size();k++){
            if(land[k][j]==1){
                v[k][j] = j1;
            }else{
                break;
            }
        }
        temp.push_back(k-1);
        j = j1;
        temp.push_back(j);
        // j1 = k-1;
        // temp.push_back(j);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>v(land.size(),vector<int>(land[0].size(),-1));
        vector<vector<int>>res;
        // display(v);
        for(int i=0;i<land.size();i++){
            vector<int>temp;
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    if(v[i][j]!=-1){
                        j=v[i][j];
                    }else{
                        getEnd(land,v,i,j,temp);
                        // v[i][j] = t;
                        res.push_back(temp);
                        // j = 
                        temp.clear();
                    }
                }
            }
        }
        display(v);
        return res;
    }
};
