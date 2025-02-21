class Solution {
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

    int checkForStart(vector<vector<int>>& land,int i,int j){
        if(i-1<0 && j-1<0){
            return 1;
        }
        if(i-1<0){
            if(land[i][j-1]==1){
                return 0;
            }else{
                return 1;
            }
        }
        
        if(j-1<0){
            if(land[i-1][j]==1){
                return 0;
            }else{
                return 1;
            }
        }
        if(land[i-1][j]==0 && land[i][j-1]==0){
            return 1;
        }
        return 0;
    }
    
    void updateTemp(vector<vector<int>>&land, int i, int j, vector<int>&t1,vector<vector<int>> &t2){
        if(i+1>=land.size() && j+1>=land[0].size()){
            t1[0] = i;
            t1[1] = j;
            t2[j][0] = i;
            t2[j][1] = j;
            return;
        }
        if(j+1>=land[0].size()){
            if(land[i+1][j]==0){
                t1[0] = i;
                t1[1] = j;
                t2[j][0] = i;
                t2[j][1] = j;
                // cout<<t1[j][0]<<" ";
                // cout<<t1[j][1]<<"\n";
                return;
            }
            t1[0] = t2[j][0];
            t1[1] = t2[j][1];
            // cout<<t1[j][0]<<" ";
            // cout<<t1[j][1]<<"\n";
            return;
        }
        if(i+1>=land.size()){ // unnecessary
            if(land[i][j+1]==0){
                t1[0] = i;
                t1[1] = j;
                t2[j][0] = i;
                t2[j][1] = j;
                // cout<<t1[j][0]<<" ";
                // cout<<t1[j][1]<<"\n";
                return;
            }
            return;
        }
        if(land[i][j+1]==0 && land[i+1][j]==0){
            t1[0] = i;
            t1[1] = j;
            t2[j][0] = i;
            t2[j][1] = j;
            return;
        }
        if(land[i][j+1]==1){
            return;
        }
        if(land[i+1][j]==1){
            t1[0] = t2[j][0];
            t1[1] = t2[j][1];
            // cout<<t1[j][0]<<" ";
            // cout<<t1[j][1]<<"\n";
            return;
        }
        return;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>res;
        vector<vector<int>>t2(land[0].size(),vector<int>(2,0));
        // cout<<t1.size();
        // cout<<t2.size();
        for(int i=land.size()-1;i>=0;i--){
            vector<int>t1(2,0);
            for(int j=land[0].size()-1;j>=0;j--){
                vector<int>v;
                if(land[i][j]==1){
                    if(checkForStart(land,i,j)==1){
                        v.push_back(i);
                        v.push_back(j);
                        updateTemp(land,i,j,t1,t2);
                        v.push_back(t1[0]);
                        v.push_back(t1[1]);
                        res.push_back(v);
                    }else{
                        updateTemp(land,i,j,t1,t2);
                    }
                }
            }
        }
        // display(res);
        // return {{}};
        return res;
    }
};
