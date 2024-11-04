class Solution {
public:
    string compressedString(string word) {
        string s = "";
        int c=0;
        for(int i=0;i<word.size();i++){
            if(i==0){
                c++;
                continue;
            }
            if(word[i]==word[i-1]){
                if(c<9){
                    c++;
                }else{
                    s.push_back(c+'0');
                    s.push_back(word[i-1]);
                    c=1;
                }
            }else{
                s.push_back(c+'0');
                s.push_back(word[i-1]);
                c=1;
            }
        }
        s.push_back(c+'0');
        s.push_back(word[word.size()-1]);
        return s;
    }
};
