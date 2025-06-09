class Solution {
public:
    void display(vector<map<char,int>>&v){
        for(int i=0;i<v.size();i++){
            cout<<"ind:"<<i<<"\n";
            for(auto y:v[i]){
                cout<<y.first<<":"<<y.second<<"\n";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(vector<string>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int searchWord(vector<map<char,int>>&m,string &s,char &c){
        int curr=1,i=0;
        if(c==s[0]){
            i++;
        }
        for(;i<s.size();i++){
            if(m[curr-1][s[i]]==0){
                return 0;
            }
            curr = m[curr-1][s[i]];
        }
        return 1;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<map<char,int>>v(s.size());
        map<char,int>m;
        if(s.size()>1){
            for(int i=s.size()-2;i>=0;i--){
                m[s[i+1]] = i+2;
                v[i]=(m);
            }
        }else{
            v[0][s[0]]=1;
        }
        // display(v);
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
