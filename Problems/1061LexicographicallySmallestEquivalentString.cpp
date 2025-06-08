class Solution {
public:
    void display(map<char,set<char>>&m){
        for(auto x:m){
            cout<<x.first<<":";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(map<char,char>m){
        for(auto x:m){
            cout<<x.first<<":"<<x.second<<"\n";
        }
        cout<<"\n";
    }
    void normalise(map<char,set<char>>&m,map<char,int>&visited,char c,map<char,char>&res){
        // cout<<"normalise "<<c<<"\n";
        if(visited[c]==1){
            return;
        }else{
            visited[c] = 1;
        }
        for(auto x:m[c]){
          /*For initial traversal*/
            if(res[x]<res[c]){
                res[c]=res[x];
            }
            if(res[c]<res[x]){
                res[x]=res[c];
            }
            normalise(m,visited,x,res);
          /*For tail (or trail) traversal*/
            if(res[x]<res[c]){
                res[c]=res[x];
            }
            if(res[c]<res[x]){
                res[x]=res[c];
            }
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,set<char>>m;
        for(int i=0;i<s1.size();i++){
            m[s1[i]].insert(s2[i]);
        }
        for(int i=0;i<s2.size();i++){
            if(s1[i]!=s2[i]){
                m[s2[i]].insert(s1[i]);
            }
        }
        // display(m);
        map<char,char>res;
        for(int i=0;i<26;i++){
            res[i+97] = i+97;
        }
        map<char,int>visited;
        for(int i=0;i<26;i++){
            normalise(m,visited,i+97,res);
        }
        // display(res);
        string s="";
        for(auto x:baseStr){
            s+=res[x];
        }
        return s;
    }
};
