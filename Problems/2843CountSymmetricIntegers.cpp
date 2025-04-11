class Solution {
public:
    int digits(int n){
        if(n<10){
            return 1;
        }
        if(n<100){
            return 2;
        }
        if(n<1000){
            return 3;
        }
        if(n<10000){
            return 4;
        }
        return 5;
    }
    int isSymmetric(int n){
        int s1=0,s2=0,c=1;
        int d = digits(n);
        if(d%2!=0){
            return 0;
        }
        while(n!=0){
            if(c<=d/2){
                s1+=n%10;
                n/=10;
            }else{
                s2+=n%10;
                n/=10;
            }
            c++;
        }
        if(s1==s2){
            return 1;
        }
        return 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            if(isSymmetric(i)){
                c++;
            }
        }
        return c;
    }
};
