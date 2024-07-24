class Solution {
public:
    int arrangeCoins(long long n) {
        long long res=0;
        long long a = sqrt(1+8*n);
        res = (a-1)/2;
        return res;
    }
};
