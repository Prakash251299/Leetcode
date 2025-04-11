class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    void display(vector<int>&v,int i,int j){
        for(;i<=j;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }

    /* For checking how many elements in array1 are bigger than twice of elements in array2 */
    int pairCount(vector<int>&v,int i1,int j1,int i2,int j2){
        int c=0,n=j1-i1+1;
        while(i1<=j1 && i2<=j2){
            long long t = (long long)2*v[i2];
            if(v[i1]>t){
                c+=(j1-i1+1);
                i2++;
                continue;
            }
            i1++;
        }
        return c;
    }

    void merge(vector<int>&v,int i1,int j1,int i2,int j2){
        vector<int>res;
        int start = i1,end = j2;
        while(1){
            if(i1<=j1 && i2<=j2){
                if(v[i1]<=v[i2]){
                    res.push_back(v[i1]);i1++;
                }else{
                    res.push_back(v[i2]);i2++;
                }
            }else{
                if(i1>j1){
                    for(int k=i2;k<=j2;k++){
                        res.push_back(v[k]);
                    }
                    break;
                }else{
                    if(i2>j2){
                        for(int k=i1;k<=j1;k++){
                            res.push_back(v[k]);
                        }
                        break;
                    }
                }
            }
        }
        for(int i=start;i<=end;i++){
            v[i] = res[i-start];
        }
    }

    void divide(vector<int>&v,int i,int j,int &c){
        if(i==j){
            return;
        }
        int mid = (i+j)/2;
        divide(v,i,mid,c);
        divide(v,mid+1,j,c);
        c+=pairCount(v,i,mid,mid+1,j);
        // display(v,i,j);
        // cout<<"i1:"<<i<<" j1:"<<mid<<" i2:"<<mid+1<<" j2:"<<j<<" val:"<<c<<"\n";
        merge(v,i,mid,mid+1,j);
        return;
    }

    int reversePairs(vector<int>& nums) {
        // vector<int>v({1,2,6,8,12,20,4,5,7,8});
        // cout<<pairCount(v,0,5,6,9);
        // return 0;




        int c=0;
        divide(nums,0,nums.size()-1,c);
        // display(nums);
        return c;
    }
};
