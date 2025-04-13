class Solution {
public:
    void display(vector<vector<int>>v){
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        // cout<<"\n";
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>v(word2.size()+1,vector<int>(word1.size()+1,0));
        for(int i=0;i<=word1.size();i++){
            v[0][i] = i;
        }
        for(int i=0;i<=word2.size();i++){
            v[i][0] = i;
        }
        for(int i=0;i<word2.size();i++){
            for(int j=0;j<word1.size();j++){
                if(word2[i]==word1[j]){
                    v[i+1][j+1] = v[i][j];
                }else{
                    int t = min(v[i][j],v[i][j+1]);
                    v[i+1][j+1] = 1 + min(t,v[i+1][j]);
                }
            }
        }
        return v[v.size()-1][v[0].size()-1];
    }
};
