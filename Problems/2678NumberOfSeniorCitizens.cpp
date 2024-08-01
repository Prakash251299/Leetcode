class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        for(int i=0;i<details.size();i++){
            int a=details[i][11]-'0';

            if(int(details[i][11])-'0'>6){
                c++;
            }
            if(a==6 && details[i][12]-'0'>0){
                c++;
            }
        }
        return c;
    }
};
