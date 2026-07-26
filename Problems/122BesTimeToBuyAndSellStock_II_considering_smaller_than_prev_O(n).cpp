class Solution {
public:
    int maxProfit(vector<int>& p) {
        int a=0,res=0,temp=0;
        for(int i=1;i<p.size();i++){
            if(i==p.size()-1){
                if(p[i]<p[i-1]){
                    res+=temp;
                    temp=0;
                    a=i;
                }else{
                    res+=p[i]-p[a];
                }
            }else{
                if(p[i]>p[i-1]){
                    temp=p[i]-p[a];
                }
                else{
                    res+=temp;
                    temp=0;
                    a=i;
                }
            }
        }
        return res;
    }
};
