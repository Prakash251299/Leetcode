class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int i=0,j=v.size()-1,c=0,count=0;
        for(auto x:v){
            if(x!=val){
                count++;
            }
        }
        for(i=0;i<j;i++){ // For left to right
            if(v[i]==val){
                for(;j>i;j--){ // For right to left
                    if(v[j]!=val){
                        c = v[i];
                        v[i] = v[j];
                        v[j] = c;
                        break;
                    }else{
                    }
                }
            }
        }
        return count;
    }
};