class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> s;
        int i=0;
        int len = digits.length();
        string temp = "";
        vector<string> val={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(len==0){
            return s;
        }
        if(len==1){
            int n=stoi(digits);
            for(i=0;i<val[n-2].length();i++){
                s.push_back(string(1,val[n-2][i]));
                // cout<<val[n-2][i];
            }
            return s;
        }else
        if(len==2){
            // cout<<int(digits[0])-'0';
            for(i=0;i<val[int(digits[0])-'0'-2].length();i++){
                for(int j=0;j<val[int(digits[1])-'0'-2].length();j++){
                    temp = string(1,val[int(digits[0])-'0'-2][i])+string(1,val[int(digits[1])-'0'-2][j]);
                    s.push_back(temp);
                }
                
            }
        }else
        if(len==3){
            for(i=0;i<val[int(digits[0])-'0'-2].length();i++){
                for(int j=0;j<val[int(digits[1])-'0'-2].length();j++){
                    for(int k=0;k<val[int(digits[2])-'0'-2].length();k++){
                        temp = string(1,val[int(digits[0])-'0'-2][i])+string(1,val[int(digits[1])-'0'-2][j])+string(1,val[int(digits[2])-'0'-2][k]);
                        s.push_back(temp);
                    }
                }
                
            }
        }else
        if(len==4){
            for(i=0;i<val[int(digits[0])-'0'-2].length();i++){
                for(int j=0;j<val[int(digits[1])-'0'-2].length();j++){
                    for(int k=0;k<val[int(digits[2])-'0'-2].length();k++){
                        for(int l=0;l<val[int(digits[3])-'0'-2].length();l++){
                            temp="";
                            temp = string(1,val[int(digits[0])-'0'-2][i])+string(1,val[int(digits[1])-'0'-2][j])+string(1,val[int(digits[2])-'0'-2][k])+string(1,val[int(digits[3])-'0'-2][l]);
                            s.push_back(temp);
                        }
                    }
                }
                
            }
        }
        return s;
    }
};