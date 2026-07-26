class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int maxProfit(vector<int>& p) {
        if(p.size()<2)return 0;
        vector<int>vrl(p.size(),-1);
        vector<int>vlr(p.size(),-1);
        vrl[vrl.size()-1]=0;
        int m = p[p.size()-1];
        for(int i=p.size()-2;i>=0;i--){
            if(p[i]>m){
                m=p[i];
            }
            int v=m-p[i];
            vrl[i]=max(v,vrl[i+1]);
        }
        // cout<<"vrl:\n";
        // display(vrl);
        m = p[0];
        vlr[0]=0;
        for(int i=1;i<p.size();i++){
            if(p[i]<m){
                m=p[i];
            }
            int v=p[i]-m;
            vlr[i]=max(v,vlr[i-1]);
        }
        // cout<<"vlr:\n";
        // display(vlr);
        int res=0;
        for(int i=0;i<p.size();i++){
            int a = vlr[i];
            int b=0;
            if(i+1<p.size()){
                b = vrl[i+1];
            }
            res = max(a+b,res);
        }
        return res;
    }
};
