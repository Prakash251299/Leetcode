// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         string s1="",s2="";
//         int top1=-1,top2=-1;
//         // if(s.size()>0)
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='#'){
//                 s1[top1] = ' ';
//                 top1--;
//             }else{
//                 top1++;
//             }
//         }
//         for(int i=0;i<t.size();i++){
//             if(t[i]=='#'){
//                 s2[top2] = ' ';
//                 top2--;
//             }else{
//                 top2++;
//             }
//         }
//         if(s1==s2){
//             return true;
//         }
//         return false;
        
//     }
// };


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = processString(s);
        int p = processString(t);

        if (k != p) return false;

        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }

private:
    int processString(string& str) {
        int k = 0;
        for (char c : str) {
            if (c != '#') {
                str[k++] = c;
            } else if (k > 0) {
                k--;
            }
        }
        return k;
    }
};
