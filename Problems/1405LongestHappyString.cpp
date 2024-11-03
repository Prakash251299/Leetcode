class Solution {
public:
    void display(vector<char>v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    void getMaxArray(vector<char>&v,int a,int b,int c){
        if(a>b && a>c){
            if(b>=c){
                v[0] = 'a';
                v[1] = 'b';
                v[2] = 'c';
            }else{
                v[0] = 'a';
                v[1] = 'c';
                v[2] = 'b';
            }
            return;
        }
        if(b>a && b>c){
            if(a>=c){
                v[0] = 'b';
                v[1] = 'a';
                v[2] = 'c';
            }else{
                v[0] = 'b';
                v[1] = 'c';
                v[2] = 'a';
            }
            return;
        }
        if(c>a && c>b){
            if(a>=b){
                v[0] = 'c';
                v[1] = 'a';
                v[2] = 'b';
            }else{
                v[0] = 'c';
                v[1] = 'b';
                v[2] = 'a';
            }
            return;
        }
        if(a==b && a>c){
            v[0] = 'a';
            v[1] = 'b';
            v[2] = 'c';
            return;
        }
        if(a==c && a>b){
            v[0] = 'a';
            v[1] = 'c';
            v[2] = 'b';
            return;
        }
        if(b==c && b>a){
            v[0] = 'b';
            v[1] = 'c';
            v[2] = 'a';
            return;
        }
        v[0] = 'a';
        v[1] = 'b';
        v[2] = 'c';
        return;
    }
    string longestDiverseString(int a, int b, int c) {
        char curr = ' ';
        int val = 0;
        string s = "";
        vector<char>v(3,' ');
        while(1){
            getMaxArray(v,a,b,c);
            if((b==0 && c==0)||(a==0 && c==0)||(b==0 && a==0)){
                if(a==0 && b==0 && c==0){
                    break;
                }
                if(v[0]==curr){
                    if(val==1){
                        s+=v[0];
                    }else{
                        break;
                    }
                }else{
                    if(v[0]=='a'){
                        s+='a';
                        a--;
                        if(a>0){
                            s+='a';
                        }
                        break;
                    }
                    if(v[0]=='b'){
                        s+='b';
                        b--;
                        if(b>0){
                            s+='b';
                        }
                        break;
                    }
                    if(v[0]=='c'){
                        s+='c';
                        c--;
                        if(c>0){
                            s+='c';
                        }
                        break;
                    }
                }
                break;
            }
            if(val<2){
                if(s.size()>0 && v[0]==s[s.size()-1]){
                    val++;
                }else{
                    val=1;
                }
                s += v[0];
                curr = v[0];
            }else{
                val=1;
                if(curr!=v[0]){
                    s+=v[0];
                    curr=v[0];
                }else{
                    s+=v[1];
                    curr = v[1];
                }
            }
            if(s[s.size()-1]=='a'){
                a--;
            }else{
                if(s[s.size()-1]=='b'){
                    b--;
                }else{
                    if(s[s.size()-1]=='c'){
                        c--;
                    }
                }
            }
        }
        // display(v);
        // cout<<s;
        return s;
    }
};
