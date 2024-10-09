class Solution {
public:
    void display(vector<vector<int>>v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>v(p.size()+1,vector<int>(s.size()+1,0));
        v[0][0]=1;
        for(int i=1;i<p.size()+1;i++){
            if(p[i-1]=='*'){
                if(i-2>=0){
                v[i][0] = v[i-2][0];
                }
            }
        }
        for(int i=1;i<p.size()+1;i++){
            for(int j=1;j<s.size()+1;j++){
                if(p[i-1]==s[j-1]){
                    v[i][j] = v[i-1][j-1];
                }else{
                    if(p[i-1]=='.'){
                        v[i][j] = v[i-1][j-1];
                    }else{
                        if(p[i-1]=='*'){
                            if(p[i-2]==s[j-1]||p[i-2]=='.'){
                                v[i][j] = v[i][j-1]||v[i][j];
                            }
                            if(i-3>=0){
                                if(s[j-1]==p[i-3]||p[i-3]=='.'||p[i-3]=='*'){
                                    v[i][j] = v[i-2][j]||v[i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
        return v[v.size()-1][v[0].size()-1];
    }
};
