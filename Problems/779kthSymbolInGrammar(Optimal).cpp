class Solution {
public:
    int findPowOfTwo(int k){
        int i=0;
        for(i=0;;i++){
            if(pow(2,i)>k){
                return i-1;
            }
        }
        // return i;
    }
    int kthGrammar(int n, int k) {
        if(k==1){  // If k becomes 1 just return 0 as at 0th index 0 is present
            return 0;
        }
        
        int a = findPowOfTwo(k); // Finds number that is power of 2 and just less than k
        if(k==pow(2,a)){ // If k matches then 
            if(a%2==0){ // if index is even then 0 will be at kth index as observation
                return 0;
            }else{       // else 1 will at kth index
                return 1;
            }
        }
        // If k does not become power of 2 then subtract the number
        //(i.e. power of 2 and just less than k)
        return !kthGrammar(1,k-pow(2,a)); // No need of n
    }
};



// Brute force method O(2^30)

// class Solution {
// public:
//     string opp(string a){
//         string s="";
//         for(int i=0;i<a.size();i++){
//             if(a[i]=='0'){
//                 s = s+'1';
//             }else{
//                 s = s+'0';
//             }
//         }
//         return s;
//     }
//     int kthGrammar(int n, int k) {
//         string s="0";
//         // s = opp(s);
//         for(int i=1;i<n;i++){
//             s = s + opp(s);
//             if(s.size()>k){
//                 return s[k-1]-'0';
//             }
//         }
//         cout<<s[0];
//         // return v[k-1];
//         return s[k-1]-'0';
//     }
// };
