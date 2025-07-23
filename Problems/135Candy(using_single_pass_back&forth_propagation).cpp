class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1){return 1;}
        vector<int>r=ratings;
        int n=r.size();
        vector<int>res(n,0);
        if(r[0]<r[1]){
            res[0]=1;
        }
        int i=1;
        while(i<n){
            if(r[i]>r[i-1]){
                res[i]=res[i-1]+1;i++;continue;
            }
            for(;i<n;i++){
                if(r[i]>r[i-1]){break;}
            }
            int j=i-1;res[j]=1;j--;
            for(;j>=0;j--){
                if(r[j]<r[j+1])break;
                if(r[j]==r[j+1]){
                    res[j]=max(1,res[j]);continue;
                }
                res[j]=max(res[j],res[j+1]+1);
            }
        }
        int c=0;
        for(auto x:res){
            c+=x;
        }
        return c;
    }
};
