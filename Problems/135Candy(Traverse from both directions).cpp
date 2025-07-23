class Solution {
public:
    int candy(vector<int>& ratings) {
        //if(ratings.size()==1)return 1;
        vector<int>res(ratings.size(),0);
        vector<int>r=ratings;
        res[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(r[i]>r[i-1]){
                res[i]=res[i-1]+1;
            }else{
                res[i]=1;
            }
        }
        res[r.size()-1]=max(1,res[r.size()-1]);
        for(int i=r.size()-2;i>=0;i--){
            if(r[i]>r[i+1]){
                res[i]=max(res[i],res[i+1]+1);
            }else{
                res[i]=max(1,res[i]);
            }
        }
        int c=0;
        for(auto x:res){
            c+=x;
        }
        return c;
    }
};
