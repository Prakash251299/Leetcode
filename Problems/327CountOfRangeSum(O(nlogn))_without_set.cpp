class Solution {
public:
    void display(unordered_map<int,int>&rank){
        for(auto x:rank){
            cout<<x.first<<":"<<x.second<<" ";
        }
        cout<<endl;
    }
    void display(vector<int>&bit){
        for(auto x:bit){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void propagate(long long sum,unordered_map<int,int>&rank,vector<int>&bit,int n){
        long long l=rank[sum];
        while(l<n){
            bit[l]++;
            l+=l&-l;
        }
    }

    long long findCountInRange(long long &sum, int low, int up, unordered_map<int,int>&rank,vector<int>&bit){
        long long c1=0,c2=0,l=rank[sum-low],u=rank[sum-up]-1;
        while(l>0){
            c1+=bit[l];
            l-=l&-l;
        }
        while(u>0){
            c2+=bit[u];
            u-=u&-u;
        }
        return c1-c2;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        unordered_map<int,int>rank;
        set<long long>pset;
        vector<long long>psum;
        long long ps=0;

        psum.push_back(0);
        for(auto x:nums){
            ps+=x;
            psum.push_back(ps);
            psum.push_back(ps-lower);
            psum.push_back(ps-upper);
        }
        sort(psum.begin(), psum.end());
        psum.erase(unique(psum.begin(), psum.end()), psum.end());

        int i=1;
        for(auto x:psum){
            rank[x]=i;
            i++;
        }
        vector<int>bit(psum.size()+1,0);
        int n = psum.size()+1;
        propagate(0,rank,bit,n);
        long long sum=0,res=0;
        for(auto x:nums){
            sum += x;
            long long val = findCountInRange(sum,lower,upper,rank,bit);
            res += val;
            propagate(sum,rank,bit,n);
        }
        return res;
    }
};
