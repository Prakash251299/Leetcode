class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        long long x = n;
        // n=8 then 8 & 7==0 is true which shows 8 is power of two
        // as 1000 & 0111 == 0 is true
        return (x & x-1)==0;
    }
};
