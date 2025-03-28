class Solution {
public:
    int check(long long mid,vector<int>ranks,int cars){
        int c=0;
        for(auto x:ranks){
            c+= sqrt(double(mid/x));
            if(c>=cars){
                return 1;
            }
        }
        return 0;
    }

    long long calculate(long long i,long long j,vector<int>ranks,int cars){
        long long best = 0;
        cout<<"j:"<<j<<"\n";
        while(i<=j){
            long long mid=(i+j)/2;
            if(check(mid,ranks,cars)==1){
                j = mid-1;
                best = mid;
            }else{
                i = mid+1;
            }
        }
        return best;
    }

    long long maxfun(vector<int>v){
        int max = 0;
        for(auto x:v){
            if(x>=max){
                max = x;
            }
        }
        return max;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long max = maxfun(ranks);
        long long min=1;
        max = max*cars*cars;
        cout<<max<<"\n";
        long long res = calculate(min,max,ranks,cars);
        return res;
    }
};
