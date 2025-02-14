class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0,r=0,i=0,max=0;
        // left to right traversal
        while(i<s.size()){
            if(s[i]=='('){
                l++;
            }else{
                r++;
                if(l<r){
                    l=0;r=0;
                }else{
                    if(l==r){
                        if(max<r*2){
                            max = r*2;
                        }
                    }
                }
            }
            i++;
        }
        i=s.size()-1;
        l=0;r=0;
        // right to left traversal
        while(i>=0){
            if(s[i]==')'){
                l++;
            }else{
                r++;
                if(l<r){
                    l=0;r=0;
                }else{
                    if(l==r){
                        if(max<r*2){
                            max = r*2;
                        }
                    }
                }
            }
            i--;
        }
        return max;
    }
};
