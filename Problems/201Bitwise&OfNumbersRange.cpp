// shifting left and right to the right so that its common prefix can be found after which we perform same 
number of left shifts so that the Bitwise AND result of numbers between them could be found
 
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int res = left;
        int count = 0;
        for(;;){
            if(left == 0 || right == 0){
                return 0;
            }
            if(left==right){
                for(int j=0;j<count;j++){
                    left = left<<1;
                }
                return left;
            }
            left = left>>1; 
            right = right>>1;
            // cout<<left<<" "<<right<<"\n";
            count++;
        }
        return 0;
    }
};
