class Solution {
public:
    int isPalindrome(string str){
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (str == rev)
            return 1;
        else
            return 0;
    }
    void fun(string s,int i,vector<string>v,vector<vector<string>>&res){
        if(i>=s.size()){
            res.push_back(v);
            return;
        }
        string t = "";
        for(int j=i;j<s.size();j++){
            t.push_back(s[j]);
            if(isPalindrome(t)==1){
                v.push_back(t);
                fun(s,j+1,v,res);
                v.pop_back();
            }
        }
        return;
    }  
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        fun(s,0,{},res);
        return res;
    }
};
