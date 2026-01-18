class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hb, vector<int>& vb) {
        sort(hb.begin(),hb.end());
        sort(vb.begin(),vb.end());
        int h=1,v=1,t=1;
        for(int i=1;i<hb.size();i++){
            if(hb[i]-1==hb[i-1]){
                t++;
            }else{
                t=1;
            }
            if(h<t){
                h=t;
            }
        }
        //cout<<"h:"<<h<<"\n";
        t=1;
        for(int i=1;i<vb.size();i++){
            if(vb[i]-1==vb[i-1]){
                t++;
            }else{
                t=1;
            }
            if(v<t){
                v=t;
            }
        }
        //cout<<"v:"<<v<<"\n";
        if(h<v){
            return (h+1)*(h+1);
        }
        return (v+1)*(v+1);
    }
};
