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
        string str="";
        int j=25,count=0;
        i = searchForCharacter(v,i);
        j = i;
        while(1){
            if(v[i]>0 && count<repeatLimit){
                str.push_back(char(i+int('a')));
                --v[i];count++;
                continue;
            }
            if(v[i]<=0){
                if(i==j){
                    i = searchForCharacter(v,i-1);
                    j = i;
                    if(i<0){
                        return str;
                    }
                    count=0;
                    continue;
                }else{
                    if(j<0){
                        return str;
                    }else{
                        i=j;
                        count=0;
                        continue;
                    }
                }
            }
            if(count>=repeatLimit){
                if(i!=j && j>=0){
                    if(v[j]>0){
                        str.push_back(char(j+int('a')));
                        --v[j];
                        count=0;
                        continue;
                    }
                }
                j = searchForCharacter(v,j-1);
                if(j<0){
                    return str;
                }
                str.push_back(char(j+int('a')));
                --v[j];
                count=0;
            }
        }
        return str;
    }
};
