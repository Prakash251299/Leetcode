class Solution {
public:
    void display(vector<int>&v){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void getPremax(vector<int>&v,vector<int>&premax){
        premax[0]=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]>=premax[i-1]){
                premax[i]=v[i];
            }
            else{
                premax[i]=premax[i-1];
            }
        }
        return;
    }
    void getSuffmin(vector<int>&v,vector<int>&suffmin){
        suffmin[v.size()-1]=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]<=suffmin[i+1])
                suffmin[i]=v[i];
            else
                suffmin[i]=suffmin[i+1];
        }
    }
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>premax(arr.size(),0);
        vector<int>suffmin(arr.size(),0);
        getPremax(arr,premax);
        getSuffmin(arr,suffmin);
        //display(premax);
        //display(suffmin);
        int i=-1,j=suffmin[0],c=1;
        for(int i=1;i<arr.size();i++){
            if(premax[i-1]<=suffmin[i]){
                c++;
            }
        }
        return c;
    }
};
