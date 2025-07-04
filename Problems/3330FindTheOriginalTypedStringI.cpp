class Solution {
public:
    void display(vector<int>&v){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    int possibleStringCount(string word) {
        vector<int>v;
        char prev=word[0];
        // cout<<prev;
        int c=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                c+=1;
            }else{
                v.push_back(c);
                c=1;
                prev=word[i];
            }
        }
        v.push_back(c);
        // display(v);
        c=0;
        for(auto x:v){
            c+=(x-1);
        }
        return c+1;
    }
};
