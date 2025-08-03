class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    vector<int> rightmostSmaller(vector<int>&arr){
        vector<int>minarr(arr.size(),0);
        int maxn=*max_element(arr.begin(),arr.end());
        minarr[arr.size()-1]=arr[arr.size()-1];
        for(int i =arr.size()-2;i>=0;i--){
            if(arr[i]<minarr[i+1]){
                minarr[i]=arr[i];
            }else{
                minarr[i]=minarr[i+1];
            }
        }
        vector<int>exist(maxn+1,0);
        for(int i=0;i<minarr.size();i++){
            exist[minarr[i]]=1;
        }
        int prev=-1;
        vector<int>minCont(maxn+1,-1);
        for(int i=0;i<=maxn;i++){
            if(exist[i]==1){
                minCont[i]=i;
                prev=i; continue;
            }
            minCont[i]=prev;
        }
        //display(arr);
        //cout<<"initial minCont\n";
        //display(minCont);
        unordered_map<int,int>visited;
        for(auto x:minCont){
            visited[x]=1;
        }
        for(int i=0;i<minCont.size();i++){
            if(minCont[i]>=i){
                minCont[i]=-1;
            }
        }
        //cout<<"final minCont\n";
        //display(minCont);
        vector<int>res;
        for(auto x:arr){
            res.push_back(minCont[x]);
        }
        
        ////////// For index of smaller elements
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        for(int i=0;i<res.size();i++){
            if(m[res[i]]==0)
                res[i]=-1;
            else
                res[i]=m[res[i]];
        }
        ////////////
        return res;
    }

    int getMax(vector<int>&v,int i,int j){
        int maxi=v[i];
        for(;i<=j;i++){
            if(v[i]>maxi){
                maxi=v[i];
            }
        }
        return maxi;
    }

    int countChunks(vector<int>&v){
        int c=0;
        int i=0,j=v[0];
        while(i<v.size()){
            if(j==-1){
                c++;i++;
                if(i<v.size()){
                    j=v[i];
                }
                continue;
            }
            int a=getMax(v,i,j);
            if(a<=j){
                c++;
                i=j+1;
                if(i<v.size()){
                    j=v[i];
                }
            }else{
                i=j+1;j=a;
            }
        }
        return c;
    }
    
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>rmin=rightmostSmaller(arr);
        int i=0,j=rmin[0],c=0;
        return countChunks(rmin);
    }
};
