class Solution {
public:
    void display(map<int, vector<char>, greater<int>>&m){
        for(auto x:m){
            cout<<x.first<<":[";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"]\n";
        }
    }
    void display(vector<char>&v){
        for(auto x:v){
            cout<<x<<"\n";
        }
    }
    void display(vector<pair<char,int>>&p){
        for(auto x:p){
            cout<<x.first<<":"<<x.second<<"\n";
        }
    }
    int isVowel(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')return 1;
        return 0;
    }
    string sortVowels(string s) {
        string res="";
        unordered_map<char,int>ind;
        vector<pair<char,int>>count;
        int i=0;
        for(auto x:s){
            if(isVowel(x)){
                if(ind[x]==0){
                    count.push_back({x,1});
                    ind[x]=count.size();
                }else{
                    ++count[ind[x]-1].second;
                }
            }
            i++;
        }
        // display(count);
        map<int, vector<char>, greater<int>> m;
        for(auto x:count){
            if(x.second>0){
                m[x.second].push_back(x.first);
            }
        }
        // display(m);
        queue<char>q;
        for(auto x:m){
            for(auto y:x.second){
                int i=0;
                while(i<x.first){
                    q.push(y);i++;
                }
            }
        }
        
        for(auto x:s){
            if(!isVowel(x)){
                res+=x;
            }else{
                res+=q.front();
                q.pop();
            }
        }
        return res;
    }
};
