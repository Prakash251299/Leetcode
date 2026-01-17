class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void nextSmaller(vector<int>&arr,vector<int>&res){
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            //display(v);
            if(i==0){
                v.push_back(0);
                continue;
            }
            
            if(arr[v[v.size()-1]]<arr[i]){
                res[i]=v[v.size()-1]+1;
                v.push_back(i);
            }else{
                while(1){
                    if(v.empty()){
                        res[i]=0;
                        break;
                    }
                    if(arr[v[v.size()-1]]<arr[i]){
                        res[i]=v[v.size()-1]+1;
                        break;
                    }
                    v.pop_back();
                }
                v.push_back(i);
            }
        }
        //display(res);
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int>v;
        vector<int>leftv(arr.size(),0);
        vector<int>rightv(arr.size(),0);
        /*v.push_back(1);
        v.push_back(2);
        cout<<v.front();
        return 0;*/
        //display(arr);
        nextSmaller(arr,leftv);
        //display(leftv);
        vector<int>arr2=arr;
        reverse(arr2.begin(),arr2.end());
        //display(arr2);
        nextSmaller(arr2,rightv);
        for(int i=0;i<rightv.size();i++)
        rightv[i]=rightv.size()-rightv[i]-1;
        reverse(rightv.begin(),rightv.end());
        //display(rightv);
        int maxv=0;
        for(int i=0;i<arr.size();i++){
            int ar=(rightv[i]-leftv[i]+1)*arr[i];
            if(ar>maxv){
                maxv=ar;
            }
        }
        return maxv;
    }
};
