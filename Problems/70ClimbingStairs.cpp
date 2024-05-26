class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int a = 2, b = 1, c = 0;
        for(int i=2;i<n;i++){
            c = a;
            a = a+b;
            b = c;
        }
        return a;
    }
};
