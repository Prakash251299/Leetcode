class Solution {
public:
    void arrange(vector<string>& words, int i, int j, vector<string>& v, int maxWidth){
        int sz=0;
        for(int k=i;k<=j;k++){
            sz+=words[k].size();
        }
        int spaces = maxWidth-sz;
        int avg=0;
        if(j==i){
            avg = spaces;
        }else{
            avg = spaces/(j-i);
        }
        int spared=spaces-(avg*(j-i));
        if(i==j){
            spared=0;
        }
        string s = "";
        for(int k=i;k<=j;k++){
            s+=words[k];
            if(k==j && i!=j){
                break;
            }
            for(int m=0;m<avg;m++){
                s+=' ';
            }
            if(spared>0){
                s+=' ';
                spared--;
            }
        }
        v.push_back(s);
        return;
    }

    void lastArrange(vector<string>& words, int i, int j, vector<string>& v, int maxWidth){
        int c=0;
        string s=words[i];
        c+=words[i].size();
        for(int k=i+1;k<=j;k++){
            s+=' ';
            c++;
            s+=words[k];
            c+=words[k].size();
        }
        for(int k=0;k<maxWidth-c;k++){
            s+=' ';
        }
        v.push_back(s);
        return;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(maxWidth==1){
            return words;
        }
        int count=words[0].size(),i=0,j=1;
        vector<string>v;
        if(words.size()==1){
            lastArrange(words,0,0,v,maxWidth);
            return v;
        }
        for(;j<words.size();j++){
            if(count+1+words[j].size()>maxWidth){
                arrange(words,i,j-1,v,maxWidth);
                count = words[j].size();
                i=j;
                if(j==words.size()-1){
                    lastArrange(words,i,j,v,maxWidth);
                }
                continue;
            }
            if(count+1+words[j].size()==maxWidth){
                arrange(words,i,j,v,maxWidth);
                j++;
                if(j==words.size()){
                    continue;
                }
                count=words[j].size();i=j;
                if(j+1>=words.size()){
                    lastArrange(words,i,j,v,maxWidth);
                }
                // j++;
                continue;
            }
            if(j==words.size()-1){
                lastArrange(words,i,j,v,maxWidth);
                // arrange(words,i,j,v,maxWidth);
                break;
            }
            count=count+1+words[j].size();
        }
        return v;
    }
};
