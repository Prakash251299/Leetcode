class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b=0,min=k,i=0;
        for(;i<k;i++){
            if(blocks[i]=='W'){
                b++;
            }
        }
        int j = i-k;min = b;
        for(;i<blocks.size();i++){
            if(blocks[j]=='W'){
                b--;
            }
            if(blocks[i]=='W'){
                b++;
            }
            if(b<min){
                min = b;
            }
            j++;
        }
        return min;
    }
};
