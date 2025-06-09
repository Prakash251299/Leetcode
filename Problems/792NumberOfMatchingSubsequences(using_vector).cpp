class Solution {
public:
    void display(vector<string>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int searchWord(vector<vector<int>>&m,string &s,char &c){
        int curr=1,i=0;
        if(c==s[0]){
            i++;
        }
        for(;i<s.size();i++){
            if(m[curr-1][int(s[i])-97]==0){
                return 0;
            }
            curr = m[curr-1][s[i]-97];
        }
        return 1;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(s.size(),vector<int>(26,0));
        vector<int>temp(26,0);
        if(s.size()>1){
            for(int i=s.size()-2;i>=0;i--){
                temp[s[i+1]-97]=i+2;
                v[i]=temp;
            }
        }else{
            v[0][s[0]]=1;
        }
        // vector<string>res;
        int count=0;
        for(auto x:words){
            if(searchWord(v,x,s[0])){
                // res.push_back(x);
                count++;
            }
        }
        // display(res);
        return count;
    }
};
