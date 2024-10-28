class Solution {
public:
    void insertHeap(vector<int>&v){
        if(v.size()==0){
            return;
        }
        int i = v.size()-1;
        int j=i;
        while(1){
            if(i==0){
                return;
            }
            j = (i-1)/2;
            if(v[i]>v[j]){
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }else{
                break;
            }
            i=j;
        }

    }

    void heapify(vector<int>&v){
        int i=0;
        int s = v.size();
        while(1){
            if(i*2+2<s){
                if(v[i*2+2]>=v[i*2+1]){
                    if(v[i*2+2]>v[i]){
                        int t = v[i];
                        v[i] = v[i*2+2];
                        v[i*2+2] = t;
                        i = i*2+2;
                        continue;
                    }else{
                        return;
                    }
                }else{
                    if(v[i*2+1]>v[i]){
                        int t = v[i];
                        v[i] = v[i*2+1];
                        v[i*2+1] = t;
                        i = i*2+1;
                        continue;
                    }else{
                        return;
                    }
                }
            }else{
                if(i*2+1<s){
                    if(v[i*2+1]>v[i]){
                        int t = v[i];
                        v[i] = v[i*2+1];
                        v[i*2+1] = t;
                        i = i*2+1;
                        return;
                    }else{
                        return;
                    }
                }else{
                    return;
                }
            }
        }
    }

    long long maxKelements(vector<int>& nums, int k) {
        double r=0;
        vector<int>v;
        for(auto x:nums){
            v.push_back(x);
            insertHeap(v);
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            r = v[0];
            sum+=v[0];
            double d = ceil(r/3);
            v[0] = d;
            if(v.size()!=0)
            heapify(v);
        }

        return sum;
    }
};
