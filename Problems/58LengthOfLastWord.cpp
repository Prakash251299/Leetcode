class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                c++;
                count=c;
            }else{
                if(c>0)
                count=c;
                c = 0;
            }
        }
        return count;
    }
};

// Method - 2

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int siz=s.size(),count=0,flag=0;
//         for(int i=siz-1;i>=0;i--){
//             if(s[i]==' '&&flag)break;
//             if(s[i]!=' '){
//                 flag=1;
//                 count++;
//             }
//         }
//         return count;
//     }
// };
