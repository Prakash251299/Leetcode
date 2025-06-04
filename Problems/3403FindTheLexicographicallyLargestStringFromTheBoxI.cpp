class Solution {
public:
    void compareString(string s, string &max){
        if(s>max){
            max=s;
        }
    }

    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        string max="",curr="";
        int sz = word.size()-numFriends+1;
        for(int i=word.size()-1;i>=0;i--){
            if(curr.size()<sz){
                curr = word[i]+curr;
            }else{
                curr.pop_back();
                curr=word[i]+curr;
            }
            compareString(curr,max);
        }
        return max;
    }
};
