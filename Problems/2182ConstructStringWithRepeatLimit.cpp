class Solution {
public:
    void display(vector<int>v){
        for(int i=0;i<26;i++){
            cout<<char(i+int('a'))<<": "<<v[i]<<"\n";
        }
    }

    int searchForCharacter(vector<int>v,int i){
        for(;;i--){
            if(i<0){
                return -1;
            }
            if(v[i]>0){
                return i;
            }
        }
    }

    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>v(26,0);
        for(auto x:s){
            ++v[int(x)-'a'];
        }
        int i=25,prev=0;
        /* Below condition is for empty string which will never be the input as described in the constraint */
        string str="";
        int j=0;
        while(1){
            if(v[i]>0 && j<repeatLimit){
                str.push_back(char(i+int('a')));
                --v[i];j++;
                continue;
            }
            if(v[i]<=0){
                i = searchForCharacter(v,i-1);
                if(i<0){
                    return str;
                }
                j=0;
                continue;
            }
            if(j>=repeatLimit){
                prev = searchForCharacter(v,i-1);
                if(prev<0){
                    return str;
                }
                str.push_back(char(prev+int('a')));
                --v[prev];
                j=0;
            }
        }
        return str;
    }
};
