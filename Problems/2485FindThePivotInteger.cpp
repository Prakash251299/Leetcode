class Solution {
public:
    int pivotInteger(int n) {
        int i=1, j=n;
        int suml = 1, sumr=n;
        while(1){
            if(i==j){
                if(suml==sumr){
                    return i;
                }else{
                    return -1;
                }
            }
            if(suml <= sumr){
                i++;
                suml+=i;
            }else{
                j--;
                sumr+=j;
            }
        }
        return i;
    }
};
