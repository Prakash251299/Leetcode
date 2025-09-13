class Solution {
public:
long long getLogFour(long long a){
    long long c=0;
    while(a>3){
        //cout<<a<<" ";
        c++;
        a/=4;
    }
    return c;
}
long long getAllCount(long long l,long long r){
    long long c=0;
    //int p=l/4+1;
    long long log4 = getLogFour(l)+1;
    long long next=pow(4,log4);
    if(r<next){
        c+=(r-l+1)*log4;
        return c;
    }else{
        c+=(next-l)*log4;
    }
    //cout<<c<<" ";
    int p=log4+1;
    for(long long i=next;i<=r;){
        //if(i<l){i*=4;}
        if(i*4<=r){
            c+=(i*4-i)*p;
        }else{
            c+=(r-i+1)*p;
        }
        i*=4;
        p++;
    }
    return c;
}

    long long minOperations(vector<vector<int>>& queries) {
        long long c=0,a=0;
        for(int i=0;i<queries.size();i++){
            a=getAllCount(queries[i][0],queries[i][1]);
            if(a%2==0){
                c+=a/2;
            }else{
                c+=a/2+1;
            }
        }
        return c;
    }
};
