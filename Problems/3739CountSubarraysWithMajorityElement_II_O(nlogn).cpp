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
    void rankify(vector<int>& nums,map<long long,long long>&m){
        for(auto x:nums){
            m[x]=0;
        }
        int i=1;
        for(auto x:m){
            m[x.first]=i;
            i++;
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
        // if(a==0){cout<<"ishu\n";return;}
        while(a<100001){
            bit[a]++;
            a+=a&-a;
        }
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        map<long long,long long>m;
        rankify(nums,m);
        // display(m);
        vector<int>sum;
        sum.push_back(0);
        long long c=0;
        for(auto x:nums){
            if(m[x]==m[target]){
                c++;
            }else{
                c--;
            }
            sum.push_back(c);
        }
        // display(sum);
        long long res=0;
        m={};
        rankify(sum,m);
        for(int i=0;i<sum.size();i++){
            sum[i]=m[sum[i]];
        }
        // display(sum);
        vector<long long>bit(100001,0);
        for(int i=0;i<sum.size();i++){
            long long x=sum[i];
            res+=getCount(x-1,bit);
            propagate(x,bit);
        }
        return res;
    }
};
