class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;;i++){
            if(pow(4,i)==n){
                return true;
            }else{
                if(pow(4,i)>n){
                    return false;
                }
            }
        }
    }
};
