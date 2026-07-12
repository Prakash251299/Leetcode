class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(vector<long long>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(map<long long,long long>&m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
    }
    void rankify(vector<int>&v){
        unordered_map<long long,long long>m;
        vector<int>arr=v;
        sort(arr.begin(),arr.end());
        int i=1;
        for(auto x:arr){
            // if(m[x]!=0)continue;
            // if (m.find(x)!=m.end()) continue;
            if (m.count(x)) continue;
            m[x]=i;
            i++;
        }
        for(int i=0;i<v.size();i++){
            v[i]=m[v[i]];
        }
    }

    long long getCount(long long a, vector<long long>&bit){
        long long c=0;
        while(a>=1){
            c+=bit[a];
            a-=a&-a;
        }
        return c;
    }

    void propagate(long long a, vector<long long>&bit){
        long long c=0;
        while(a<bit.size()){
            bit[a]++;
            a+=a&-a;
        }
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int>sum;
        sum.push_back(0);
        long long c=0;
        for(auto x:nums){
            if(x==target){
                c++;
            }else{
                c--;
            }
            sum.push_back(c);
        }
        // display(sum);
        long long res=0;
        rankify(sum);
        vector<long long>bit(sum.size()+1,0);
        for(int i=0;i<sum.size();i++){
            long long x=sum[i];
            res+=getCount(x-1,bit);
            propagate(x,bit);
        }
        return res;
    }
};
