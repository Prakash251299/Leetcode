class Solution {
public:
    void display(vector<vector<int>>v){
        for(auto x:v){
            cout<<char(x[0])<<":"<<x[1]<<"\n";
        }
    }
    string removeOccurrences(string s, string part) {
        int i=0,j=0;
        vector<vector<int>>v;
        // for()
        // return "";
        while(i<s.size()){

            if(s[i]==part[j]){
                v.push_back({s[i],j+1});
                i++;
                j++;
                
                if(j==part.size()){
                    j=0;
                    for(int k=0;k<part.size();k++){
                        v.pop_back();
                    }
                    if(v.size()>0){
                        j = v[v.size()-1][1];
                    }
                }
            }else{
                j--;
                if(j<0){
                    v.push_back({s[i],0});
                    j=0;i++;
                }
            }
            // i++;
        }
        // display(v);
        string res="";
        for(auto x:v){
            res+=char(x[0]);
            // cout<<char(x[0])<<":"<<x[1]<<"\n";
        }
        return res;
    }
};
