class Solution {
public:
    int isPrime(int a){
    if(a==2) return 1;
    int end=sqrt(a);
    for(int i=2;i<=end;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

void propagate(int start, int l,int r,vector<int>&visited){
    for(int i=l;i<=r;i+=l){
        visited[i-start]=1;
    }
}

int countPrimeInRange(int r) {
    int l=0;
    int start=l;
    // vector<int>visited(r+1,0);
    vector<int>visited(r-l+1,0);
    //vector<int>res;
    int c=0;
    for(int i=l;i<=r;i++){
        if(i<=1){
            continue;
        }
        if(visited[i-l]==0){
            //if(isPrime(i)){
                c++;
                //res.push_back(i);
                //propagate(start,i,r,visited);
            //}
                propagate(start,i,r, visited);
        }
        //cout<<i<<": ";
        //display(visited);
    }
    //cout<<"Final:\n";
    //display(res);
    //return res.size();
    return c;
}
    int countPrimes(int n) {
        return countPrimeInRange(n-1);
    }
};
