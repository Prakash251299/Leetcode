class Solution {
public:
    int reverseCalc(vector<int>v,int i,int j,int total){ // For checking total from last 
    //(it is there so that if from a node we can't find a node till last)
        int start=i,end=i,sum=0;
        for(int k=i;k>=j;k--){
            if(v[k]>=v[start]){
                end=k;
                total = total+ calc(v,start,end,sum);
                // cout<<total<<" ";
                start = k;
                end = k;
                sum=0;
            }else{
                // if(v[i]<v[start]){
                    sum=sum+v[k];
                // }
            }
        }
        // cout<<"\n"<<total;
        return total;
    }
    
    int calc(vector<int>v,int start, int end, int sum){
        if(start==end){
            return 0;
        }
        int m=0,res=0,diff=0;
        m = min(v[start],v[end]);
        diff = end-start;
        if(diff<0){
            diff = -1*diff;
        }
        diff--;
        res = m*diff-sum;
        // cout<<res<<" ";
        return res;
    }
    
    int trap(vector<int>& height) {
        // cout<<calc(height,9,7,1);
        vector<int>v=height;
        // cout<<"\n"<<reverseCalc(v,10,6,0);
        // return 0;
        int start=0,end=0,currMax=v[0],total=0,sum=0;
        for(int i=0;i<height.size();i++){
            if(i==v.size()-1){
                end=i;
                // cout<<"hi";
                if(v[i]>=v[start]){
                    total = total+ calc(v,start,end,sum);
                    // cout<<total<<" ";
                    // sum=0;
                    return total;
                }else{
                    total = reverseCalc(v,i,start,total);
                    return total;
                }
            }
            if(v[i]>=v[start]){
                end=i;
                total = total+ calc(v,start,end,sum);
                // cout<<total<<" ";
                sum = 0;
                start = i;
                end = i;
            }
            else{
                // if(v[i]<v[start]){
                    sum = sum + v[i];
                // }
                // if(currMax<v[i]){
                //     currMax=v[i];
                // }
            }
        }
        // cout<<"hi";
        return total;
    }
};