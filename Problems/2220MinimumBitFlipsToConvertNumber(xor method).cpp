class Solution {
public:
    void intToBinary(int n,vector<int>&v){
        while(n!=0){
            if(n%2==0){
                v.push_back(0);
            }else{
                v.push_back(1);
            }
            n/=2;
        }
        return;
    }

    void display(vector<int>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }

    int minBitFlips(int start, int goal) {
        int a = start^goal; // XORing both will give a number which is having bits 1 where there is a difference in the bits of the multipliers
        // e.g.
        // 10 = 1010
        //  7 = 0111
        // 7^10 = 13 = 1101
        // 1101 shows that there are differences in the bits (1010 and 0111) at position of 1s
        vector<int>v;
        intToBinary(a,v);
        // display(v);
        int c=0;
        for(auto x:v){
            if(x==1){
                c++;
            }
        }
        return c;
    }
};
