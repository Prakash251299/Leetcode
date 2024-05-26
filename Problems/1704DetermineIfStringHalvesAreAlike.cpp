class Solution {
public:
    int vowelCal(char a){
        if(a=='a' or a=='A'){
            return 1;
        }
        if(a=='e' or a=='E'){
            return 1;
        }
        if(a=='i' or a=='I'){
            return 1;
        }
        if(a=='o' or a=='O'){
            return 1;
        }
        if(a=='u' or a=='U'){
            return 1;
        }
        return 0;
    }
    bool halvesAreAlike(string s) {
        int a=0,i=0,firstCount=0,secondCount=0;
        for(i=0;i<s.size()/2;i++){
            a = vowelCal(s[i]);
            if(a==1){
                firstCount++;
            }
        }
        for(;i<s.size();i++){
            a = vowelCal(s[i]);
            if(a==1){
                secondCount++;
            }
        }
        if(firstCount==secondCount){
            return true;
        }
        return false;
    }
};
