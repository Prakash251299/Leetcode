class Solution {
public:
    long long coloredCells(int n) {
        long long a = n/2;
        if(n%2==0){
            return (n-1+(a*n+(a-1)*(n-1))*2);
        }else{
            return (n+(a*n+a*(n-1))*2);
        }
        return 0;
    }
};
