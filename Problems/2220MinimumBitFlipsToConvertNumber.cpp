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

    void pushZeroes(vector<int>&v,int a){
        for(int i=0;i<a;i++){
            v.push_back(0);
        }
        return;
    }

    int bitCount(vector<int>v,vector<int>v1){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=v1[i]){
                c++;
            }
        }
        return c;
    }

    int minBitFlips(int start, int goal) {
        vector<int>v;
        vector<int>v1;
        intToBinary(start,v);
        intToBinary(goal,v1);
        if(v.size()<v1.size()){
            pushZeroes(v,v1.size()-v.size());
        }
        if(v.size()>v1.size()){
            pushZeroes(v1,v.size()-v1.size());
        }
        // reverse(v.begin(),v.end());
        // reverse(v1.begin(),v1.end());
        int res = bitCount(v,v1);
        // display(v);
        // display(v1);
        return res;
    }
};
