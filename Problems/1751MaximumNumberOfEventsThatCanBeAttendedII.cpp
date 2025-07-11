class Solution {
public:
    void display(vector<vector<int>>&v, int k, vector<unordered_map<int,int>>&dp){
        for(int i=0;i<=k;i++){
            for(int j=0; j<v.size(); j++){
                cout<<dp[i][v[j][1]]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<int> getSortedIndexOfVector(vector<vector<int>>&v){
        map<int,vector<int>>m;
        
        for(int i=0;i<v.size();i++){
            m[v[i][1]].push_back(i);
        }
        vector<int>indVector;
        // Pushing the indices will take O(N) time
        for(auto x:m){
            for(auto y:x.second){
                indVector.push_back(y);
            }
        }
        return indVector;
    }

    // void sortEvents(vector<vector<int>>&v){
    //     vector<int>indVec= getSortedIndexOfVector(v);
    //     vector<vector<int>>res;
    //     for(auto x:indVec){
    //         res.push_back(v[x]);
    //     }
    //     v=res;
    //     return;
    // }
    
    void binaryS(vector<int>&v,int a, int i, int j, int &num){
        if(i>j){
            return;
        }
        int mid=(i+j)/2;
        if(v[mid]<a){
            num=v[mid];
            binaryS(v,a,mid+1,j,num);
        }else{
            binaryS(v,a,i,mid-1,num);
        }
        return;
    }
    int getPrevEnd(vector<int>&v,int a){
        int num=-1;
        binaryS(v,a,0,v.size()-1,num);
        return num;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        vector<int>maxVal(k+1,0);
        vector<int>indVec= getSortedIndexOfVector(events);

        // sortEvents(events);
        // display(events);
        vector<int>v(1,0);
        vector<unordered_map<int,int>>dp(k+1);
        for(int i=0;i<events.size();i++){
            int prevEnd = getPrevEnd(v,events[indVec[i]][0]);
            for(int j=1;j<=k;j++){
                if(j==1){
                    dp[j][events[indVec[i]][1]]=max(maxVal[j],max(dp[j][events[indVec[i]][1]],events[indVec[i]][2]));
                    maxVal[j] = dp[j][events[indVec[i]][1]];
                    continue;
                }
                if(dp[j-1][prevEnd]==0){
                    if(maxVal[j]!=0){
                        dp[j][events[indVec[i]][1]] = maxVal[j];
                        continue;
                    }else
                    break;
                }
                int temp=dp[j-1][prevEnd]+events[indVec[i]][2];
                dp[j][events[indVec[i]][1]]=max(dp[j][events[indVec[i]][1]],max(temp,maxVal[j]));
                maxVal[j] = dp[j][events[indVec[i]][1]];
            }
            v.push_back(events[indVec[i]][1]);
        }
        // display(events,k,dp);
        int res=0;
        for(auto x:maxVal){
            if(x>res){
                res = x;
            }
        }
        return res;
    }
};
