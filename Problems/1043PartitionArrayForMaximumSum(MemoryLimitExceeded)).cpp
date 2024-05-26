class Solution {
public:

    int findMax(vector<int>v,int i,int j){
        if(i<0){
            i=0;
        }
        int max=v[i];
        for(int k=i;k<=j;k++){
            if(v[k]>max){
                max = v[k];
            }
        }
        return max;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        return;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int max=0,sum=0,m=0;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            max=0;
            for(int j=1;j<=k;j++){

                sum = 0;
                // if(j<0){
                //     break;
                // }
                if(i-j+1<0){
                    break;
                }
                m = findMax(arr,(i-j+1),i);
                sum += m*j;
                if(i-j>=0){
                    sum+=v[(v.size()-1)-j+1];
                    // sum+=v[(i-j)%k];
                }
                if(max<sum){
                    max = sum;
                }
            }
            // v[i%k] = max;
            v.push_back(max);
            if(v.size()==k+2){
                v.erase( v.begin() + 0 );
            }
            display(v);
            cout<<"\n";
        }
        return v[v.size()-1];
    }
};
