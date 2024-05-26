class Solution {
public:
    int divide(int dividend, int divisor) {
        long div=1;
        div = (long(dividend)/long(divisor));
        if(div<pow(-2,31)){
            return pow(-2,31);
        }
        if(div>pow(2,31)-1){
            return pow(2,31)-1;
        }
        return div;
    }
};
