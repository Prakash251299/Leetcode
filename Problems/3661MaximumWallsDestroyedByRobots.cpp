class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(vector<vector<int>>&v){
        // int i=0;
        for(auto x:v){
            // cout<<i<<":";
            // i++;
            for(auto y:x){
                cout<<y<<",";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<int> getSortedIndexOfVector(vector<int>&v){
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++){
            m[v[i]].push_back(i);
        }
        vector<int>indVector;
        for(auto x:m){
            for(auto y:x.second){
                indVector.push_back(y);
            }
        }
        return indVector;
    }
    void sortByIndex(vector<int>&v,vector<int>&indVector){
        vector<int>temp(v.size(),0);
        for(int i=0;i<v.size();i++){
            temp[i] = v[indVector[i]];
        }
        v = temp;
    }
    void findRanges(vector<int>&robots,vector<int>&distance,vector<vector<int>>&ranges){
        for(int i=0;i<robots.size();i++){
            int l=0,r=0;
            if(i==0){l=max(1,robots[i]-distance[i]);}
            else{
                l=max(robots[i-1]+1,robots[i]-distance[i]);
            }
            if(i==robots.size()-1){
                // r = robots.size()-1;
                r = robots[i]+distance[i];
            }else{
                r = min(robots[i+1]-1,robots[i]+distance[i]);
            }
            ranges[i][0]=l;
            ranges[i][1]=r;
        }
    }

    int binarySearchEqualOrLower(vector<int>&v,int target){
        int i=0,j=v.size()-1,ans =-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(v[mid]<=target){
                i=mid+1;
                ans = mid;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }
    int binarySearchLower(vector<int>&v,int target){
        int i=0,j=v.size()-1,ans =-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(v[mid]<target){
                i=mid+1;
                ans = mid;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }

    int getWallsCount(vector<int>&walls,int l, int r){
        if(l>r){return 0;}
        int indLeft=binarySearchLower(walls,l);
        // int indLeft=binarySearchEqualOrLower(walls,l-1);
        int indRight=binarySearchEqualOrLower(walls,r);
        int res = indRight-indLeft;
        // if(res<0)res=0;
        return res;
    }
    
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<int>indVector = getSortedIndexOfVector(robots);
        // cout<<"Before\n";
        // display(robots);
        sortByIndex(robots,indVector);
        sortByIndex(distance,indVector);
        // cout<<"After sort robots\n";
        // display(robots);
        // cout<<"After sort distance\n";
        // display(distance);
        vector<vector<int>>range(robots.size(),vector<int>(2,0));
        findRanges(robots,distance,range);
        // cout<<"Range\n";
        // display(range);
        sort(walls.begin(),walls.end());
        // cout<<"total walls\n";
        // display(walls);

        vector<vector<int>>wallsInRange(robots.size(),vector<int>(2,0));
        for(int i=0;i<robots.size();i++){
            int lwalls = getWallsCount(walls,range[i][0],robots[i]);
            int rwalls = getWallsCount(walls,robots[i],range[i][1]);
            wallsInRange[i] = {lwalls,rwalls};
        }
        // cout<<"wallsInRange\n";
        // display(wallsInRange);

        // getting the final wall count greedily
        int leftWalls=wallsInRange[0][0];
        int rightWalls=wallsInRange[0][1];
        for(int i=1;i<robots.size();i++){
            int temp = rightWalls;
            rightWalls = max(wallsInRange[i][1]+rightWalls,wallsInRange[i][1]+leftWalls);
            int overlappedRangeWalls = 0;
            if(range[i][0]<=range[i-1][1]){
                overlappedRangeWalls = getWallsCount(walls,range[i-1][1]+1,robots[i]);
            }else{
                overlappedRangeWalls = wallsInRange[i][0];
            }
            leftWalls = max(leftWalls+wallsInRange[i][0],temp+overlappedRangeWalls);
        }
        return max(leftWalls,rightWalls);
    }
};
