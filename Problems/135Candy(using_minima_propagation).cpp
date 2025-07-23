class Solution {
public:
    void traverse(vector<int>&ratings,int i,vector<int>&candyCount){
        // left traversal
        candyCount[i]=1;
        for(int j=i;j>=1;j--){
            if(ratings[j-1]>ratings[j]){
                candyCount[j-1]=max(candyCount[j-1],candyCount[j]+1);
            }else{
                break;
            }
        }
        // right traversal
        for(int j=i;j<ratings.size()-1;j++){
            if(ratings[j+1]>ratings[j]){
                candyCount[j+1] = max(candyCount[j+1],candyCount[j]+1);
            }else{
                break;
            }
        }
        return;
    }

    int candy(vector<int>& ratings) {
        vector<int>minima;
        if(ratings.size()==1){
            return 1;
        }
        if(ratings.size()==2){
            if(ratings[0]==ratings[1]){
                return 2;
            }else{
                return 3;
            }
        }
        if(ratings[0]<=ratings[1]){
            minima.push_back(0);
        }
        if(ratings[ratings.size()-1]<=ratings[ratings.size()-2]){
            minima.push_back(ratings.size()-1);
        }
        for(int i=1;i<ratings.size()-1;i++){
            if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                minima.push_back(i);
            }
        }
        vector<int>candyCount(ratings.size(),0);
        for(auto x:minima){
            traverse(ratings,x,candyCount);
        }
        int totalRequiredCandies = 0;
        for(auto x:candyCount){
            totalRequiredCandies+=x;
        }
        return totalRequiredCandies;
    }
};
