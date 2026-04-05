class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void display(deque<int>dq){
        while(!dq.empty()){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        cout<<"\n";
    }

    void findNext(deque<int>&dq,string &s,vector<int>&cs,vector<int>&ct,int curr,int &m){
        int j=dq.back();
        while(j<s.size()){
            if(ct[s[j]]>0){
                dq.push_back(s[j]);
                cs[s[j]]++;
            }
            if(s[curr]==s[j]){
                break;
            }
            j++;
        }
        return;
    }

    string minWindow(string s, string t) {
        vector<int>ct(128,0);
        vector<int>cs(128,0);
        deque<int>dq;
        int ts=t.size();
        int m=0;
        for(int i=0;i<t.size();i++){
            ++ct[t[i]];
        }
        for(int i=0;i<s.size();i++){
            if(ct[s[i]]>0){
                dq.push_back(i);
                if(cs[s[i]]<ct[s[i]]){
                    ts--;
                }
                ++cs[s[i]];
            }
            if(ts==0) break;
        }
        if(ts!=0)return "";
        int i=dq.front();
        int j=dq.back();
        m=j-i+1;
        int minInd=i,maxInd=j;
        j++;


        while(!dq.empty() && j<s.size()){
            int ti=dq.front();
            cs[s[ti]]--;
            dq.pop_front();
            if(cs[s[ti]]>=ct[s[ti]]){
                if(dq.back()-dq.front()+1<m){
                    m=dq.back()-dq.front()+1;
                    minInd=dq.front();
                    maxInd=dq.back();
                }
                continue;
            }
            for(;j<s.size();j++){
                if(ct[s[j]]>0){
                    dq.push_back(j);cs[s[j]]++;
                    if(s[j]==s[ti]){
                        //Found
                        while(cs[s[dq.front()]]>ct[s[dq.front()]]){
                            cs[s[dq.front()]]--;
                            dq.pop_front();
                            if(dq.back()-dq.front()+1<m){
                                m=dq.back()-dq.front()+1;
                                minInd=dq.front();
                                maxInd=dq.back();
                            }
                        }
                        if(dq.back()-dq.front()+1<m){
                            m=dq.back()-dq.front()+1;
                            minInd=dq.front();
                            maxInd=dq.back();
                        }
                        j++;
                        break;
                    }
                }
            }
        }
        i=minInd,j=maxInd;
        for(int k=0;k<cs.size();k++){
            cs[k]=0;
        }
        for(int k=minInd;k<=maxInd;k++){
            if(ct[s[k]]>0){
                cs[s[k]]++;
            }
        }
        while(i<=j){
            cout<<"cs[s[i]]: "<<cs[s[i]]<<endl;
            if(cs[s[i]]>ct[s[i]]){
                cs[s[i]]--;
                i++;
                if(j-i+1<m){
                    m=j-i+1;
                    minInd=i;
                    maxInd=j;
                }
            }else{
                if(ct[s[i]]==0){
                    i++;
                    if(j-i+1<m){
                        m=j-i+1;
                        minInd=i;
                        maxInd=j;
                    }
                    continue;
                }else{
                    break;
                }
            }
        }
        string res="";
        for(int i=minInd;i<=maxInd;i++){
            res=res+s[i];
        }
        return res;
    }
};
