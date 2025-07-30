class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    int check(vector<int>&v,int i,int j){
        int max=v[i];
        i++;
        for(;i<=j;i++){
            if(v[i]>=max){
                max=v[i];
            }
        }
        return max;
    }
    
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>v(arr.size(),0);
        int mini=INT_MAX,c=0;
        v[v.size()-1]=v.size()-1;
        for(int i=arr.size()-2;i>=0;i--){
            v[i]=i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    v[i]=j;
                }
            }
        }
        //display(v);
        int i=0,j=0;
        for(;i<arr.size();){
            j=max(j,v[i]);
            while(i<=j){
                int a=check(v,i,j);
                //int a=v[i];
                if(a<=j){
                    //cout<<a<<":"<<j<<"\n";
                    i=j+1;c++;break;
                }else{
                    i=j+1;j=a;
                }
            }
        }
        return c;
    }
};
