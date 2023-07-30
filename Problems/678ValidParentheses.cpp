class Solution {
public:
    bool checkValidString(string s) {
        int i=0,j=0,flag=0,count=0;
        for(i=0;i<s.size();i++){
            if(s[i]==')'){
                flag=0;
                for(j=i;j>=0;j--){
                    if(s[j]=='('){
                        flag=1;
                        s[i] = '.';
                        s[j] = '.';break;
                    }
                }
                if(flag==0){
                    for(j=i;j>=0;j--){
                        if(s[j]=='*'){
                            flag=1;
                            s[i] = '.';
                            s[j] = '.';break;
                        }
                    }
                    if(flag==0){
                        return false;
                    }
                }
            }
        }
        count=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='('){
                for(i=s.size()-1;i>=0;i--){
                    if(s[i]=='('){
                        if(count>0){
                            count--;
                            s[i] = '.';
                        }else{
                            return false;
                        }
                    }
                    else{
                        if(s[i]=='*'){
                            count++;
                        }
                    }
                }
                break;
            }
        }
        return true;
    }




    // char opp(char a){
    //     if(a==')'){
    //         return '(';
    //     }
    //     return ' ';
    // }
    
    // bool isOpen(char a){
    //     if(a=='('){
    //         return true;
    //     }
    //     return false;
    // }
    
    // bool checkValidString(string s) {
    //     int i=0,top=-1,count=0;
    //     vector<char>v;
    //     for(i=0;i<s.size();i++){
    //         if(isOpen(s[i])){
    //             v.push_back(s[i]);top++;
    //         }else{
    //             if(s[i]=='*'){
    //                 count++;
    //             }else{
    //                 if(top>=0 and v[top]==opp(s[i])){
    //                     v.pop_back();top--;
    //                 }else{
    //                     if(count==0){
    //                         return false;
    //                     }else{
    //                         // v.pop_back();
    //                         count--;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     if(v.size()==0){
    //         return true;
    //     }else{
    //         if(v.size()<=count){
    //             return true;
    //         }
    //         return false;
    //     }
    // }
};