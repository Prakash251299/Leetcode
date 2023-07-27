class Solution {
public:
    char opp(char a){
        if(a=='('){
            return ')';
        }
        if(a==')'){
            return '(';
        }
        if(a=='{'){
            return '}';
        }
        if(a=='}'){
            return '{';
        }
        if(a=='['){
            return ']';
        }
        if(a==']'){
            return '[';
        }
        return ' ';
    }
    
    bool isOpen(char a){
        if(a=='('||a=='['||a=='{'){
            return true;
        }
        return false;
    }
    
    bool isValid(string s) {
        int i=0;
        vector<int> v;
        
        while(i<s.size()){
            for(i=0;i<s.size();i++){
                if(v.size()==0){
                    if(isOpen(s[i])){
                        v.push_back(s[i]);
                    }else{
                        return false;
                    }
                }else{
                    if(isOpen(s[i])){
                        v.push_back(s[i]);
                    }else{
                        if(v[v.size()-1]==opp(s[i])){
                            v.pop_back();
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        if(v.size()==0){
            return true;
        }
        return false;
    }
};