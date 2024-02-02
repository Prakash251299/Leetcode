class Solution {
public:
    /* Method - 1 (Recursion) */
    void fun(string s1, int a, int j, int n, vector<int>&v,int low,int high){
        if(j>n){
            if(stol(s1)>=low and stol(s1)<=high){
                v.push_back(stoi(s1));
            }
            return;
        }
        if(a>9){
            return;
        }
        s1+=to_string(a);
        fun(s1,a+1,j+1,n,v,low,high);
        return;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        int j=0;
        string s1="";
        for(int n=1;n<=9;n++){
            for(int i=1;i<10;i++){
                s1+=to_string(i);
                fun(s1,i+1,j+1,n,v,low,high);
                s1="";
            }
        }
        return v;
    }


    /* Method - 2 (Direct approach) */

    // vector<int> sequentialDigits(int low, int high) {
    //     vector<int>v;
    //     int m[37] = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
    //     for(int i=0;i<37;i++){
    //         if(m[i]>high){
    //             break;
    //         }
    //         if(m[i]>=low){
    //             v.push_back(m[i]);
    //         }
    //     }
    //     return v;
    // }
};
