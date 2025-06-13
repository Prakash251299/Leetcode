class Solution {
public:
    void display(map<string,vector<string>>&m){
        for(auto x:m){
            cout<<x.first<<":";
            for(auto y:x.second){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void display(queue<string>v){
        while(!v.empty()){
            cout<<v.front()<<" ";
            v.pop();
        }
        cout<<"\n";
    }
    void storePattern(string s,map<string,set<string>>&m){
        for(int i=0;i<s.size();i++){
            string temp = s;
            temp[i] = '*';
            m[temp].insert(s);
            m[s].insert(temp);
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=1;
        map<string,set<string>>m;
        for(auto x:wordList){
            storePattern(x,m);
        }
        // display(m);
        queue<string>a;
        queue<string>b;
        for(int i=0;i<beginWord.size();i++){
            string temp = beginWord;
            temp[i] = '*';
            b.push(temp);
        }
        // display(b);
        int found=0;
        map<string,int>visited;
        visited[beginWord] = 1;
        while(!b.empty() || !a.empty()){
            // here the main code of searching and matching
            if(!a.empty() && a.front()==endWord){
                break;
            }
            int flag=0;
            while(!b.empty()){
                if(visited[b.front()]==1){
                    b.pop();
                    continue;
                }
                visited[b.front()]=1;
                for(auto x:m[b.front()]){
                    if(visited[x]==0){
                        flag=1;
                        visited[x]=1;
                        if(x==endWord){
                            found=1;
                            break;
                        }
                        a.push(x);
                    }
                }
                b.pop();
                if(found==1){
                    if(flag==1){
                        res++;
                    }
                    break;
                }
            }
            if(found==1){
                break;
            }
            if(flag==1){
                res++;
            }
            while(!a.empty()){
                for(auto x:m[a.front()]){
                    if(visited[x]==0){
                        b.push(x);
                    }
                }
                a.pop();
            }
        }
        if(found==0){
            return 0;
        }
        return res;
    }
};
